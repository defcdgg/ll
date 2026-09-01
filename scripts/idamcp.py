#!/usr/bin/env python3
"""
idamcp.py -- 给 shell 用的 ida-mcp 瘦客户端 (pi 无 MCP, 直接走 stdio JSON-RPC)

  ./scripts/idamcp.py tools                       # 列工具
  ./scripts/idamcp.py call status '{}'            # 调工具
  ./scripts/idamcp.py call open_idb '{"path":"/x/i64 或 /x/gba","new":true}'
  ./scripts/idamcp.py call list_functions '{"limit":20}'
  ./scripts/idamcp.py raw '{"name":"decompile","arguments":{"address":"0x08007a1c"}}'

会话状态在 IDA 服务端进程里, 所以每次调用都会拉起一个进程 —— 为了跨调用保持
数据库打开, 用 --session 复用一个后台 serve 进程 (见 idamcp.sh 的 start/stop)。
最省事的方式: 一条命令里连续 call 多个工具 (见 `multi`)。

  ./scripts/idamcp.py multi reqs.jsonl            # 每行一个 {"name":..,"arguments":{..}}
"""
import json, os, subprocess, sys

BIN = os.environ.get("IDA_MCP_BIN", "/home/gpnux/ida-mcp-rs/ida-mcp")


class Client:
    def __init__(self, extra=()):
        self.p = subprocess.Popen([BIN, "serve", *extra], stdin=subprocess.PIPE,
                                  stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
                                  text=True, bufsize=1)
        self._id = 0
        self.rpc("initialize", {"protocolVersion": "2024-11-05",
                                "capabilities": {},
                                "clientInfo": {"name": "pi-idamcp", "version": "1"}})
        self.p.stdin.write(json.dumps({"jsonrpc": "2.0", "method": "notifications/initialized"})
                           + "\n")
        self.p.stdin.flush()

    def rpc(self, method, params=None):
        self._id += 1
        mid = self._id
        msg = {"jsonrpc": "2.0", "id": mid, "method": method}
        if params is not None:
            msg["params"] = params
        self.p.stdin.write(json.dumps(msg) + "\n")
        self.p.stdin.flush()
        while True:
            line = self.p.stdout.readline()
            if not line:
                raise RuntimeError("ida-mcp 进程结束")
            try:
                r = json.loads(line)
            except json.JSONDecodeError:
                continue
            if r.get("id") == mid:
                if "error" in r:
                    raise RuntimeError(json.dumps(r["error"]))
                return r["result"]

    def tools(self):
        return self.rpc("tools/list", {})

    def call(self, name, args):
        r = self.rpc("tools/call", {"name": name, "arguments": args})
        out = []
        for c in r.get("content", []):
            if c.get("type") == "text":
                out.append(c["text"])
            else:
                out.append(json.dumps(c))
        if r.get("isError"):
            out.append("[isError]")
        return "\n".join(out)

    def close(self):
        try:
            self.p.stdin.close()
            self.p.wait(timeout=5)
        except Exception:
            self.p.kill()


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return
    cmd = sys.argv[1]
    extra = os.environ.get("IDA_MCP_ARGS", "").split()
    c = Client(extra)
    try:
        if cmd == "tools":
            for t in c.tools().get("tools", []):
                print(f"{t['name']:28s} {t.get('description','')[:90]}")
        elif cmd == "call":
            name = sys.argv[2]
            args = json.loads(sys.argv[3]) if len(sys.argv) > 3 else {}
            print(c.call(name, args))
        elif cmd == "multi":
            for line in open(sys.argv[2]):
                line = line.strip()
                if not line:
                    continue
                q = json.loads(line)
                print(f"### {q['name']} {q.get('arguments',{})}")
                try:
                    print(c.call(q["name"], q.get("arguments", {})))
                except Exception as e:
                    print("ERROR", e)
        elif cmd == "raw":
            print(json.dumps(c.rpc(sys.argv[2] if len(sys.argv) > 2 else "tools/list",
                                   json.loads(sys.argv[3]) if len(sys.argv) > 3 else {}),
                             ensure_ascii=False))
    finally:
        c.close()


if __name__ == "__main__":
    main()
