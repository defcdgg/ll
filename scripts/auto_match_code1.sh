#!/usr/bin/env bash
# Run the code_1 short-function batch matcher with the project's Python env.
set -euo pipefail
cd "$(dirname "$0")/.."
exec .venv/bin/python scripts/auto_match_code1.py --apply "$@"
