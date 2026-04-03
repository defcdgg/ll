#!/bin/bash
set -e

echo "=== Lunar Legend Decompilation - Setup ==="
echo ""


build_tool(){
    echo ""
    if [ -f tools/$1/$1 ]; then
        echo "$1 is up-to-date, skip build."
    else
        echo "Building $1..."
        cd tools/$1
        make
        if [ ! -f $1 ]; then
            echo "Error: $1 failed to build."
            exit 1
        fi
        cd ../../
    fi
}

# Check for required tools
check_tool() {
    if ! command -v "$1" &> /dev/null; then
        echo "Error: $1 is not installed."
        echo "$2"
        exit 1
    fi
}

check_tool arm-none-eabi-as "Install ARM GNU Toolchain: https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads"
check_tool arm-none-eabi-ld "Install ARM GNU Toolchain: https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads"
check_tool arm-none-eabi-objcopy "Install ARM GNU Toolchain: https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads"
check_tool make "Install make via your package manager."

# Check for baserom
if [ ! -f baserom.gba ]; then
    echo "Error: baserom.gba not found."
    echo "Place your Lunar Legend (Japan) ROM as baserom.gba in the project root."
    echo "Expected SHA1: 483b2c37330cf914c121801acd9f15776f92eb29"
    exit 1
fi

# Verify baserom SHA1
echo "Verifying baserom.gba..."
SHA1_CMD=$(command -v sha1sum || command -v shasum)
ACTUAL_SHA1=$($SHA1_CMD baserom.gba | cut -d' ' -f1)
EXPECTED_SHA1="483b2c37330cf914c121801acd9f15776f92eb29"

if [ "$ACTUAL_SHA1" != "$EXPECTED_SHA1" ]; then
    echo "Error: baserom.gba SHA1 mismatch."
    echo "  Expected: $EXPECTED_SHA1"
    echo "  Got:      $ACTUAL_SHA1"
    echo "Make sure you have the correct ROM."
    exit 1
fi
echo "baserom.gba: OK"

# Clean generated files
echo "Cleaning generated files..."
rm -rf asm/nonmatchings build

# Init submodules
echo ""
echo "Initializing submodules..."
git submodule update --init

# Build agbcc (skip if cached and up-to-date)
echo ""
AGBCC_CACHE_FILE="tools/agbcc/.build_cache"
AGBCC_COMMIT=$(git -C tools/agbcc rev-parse HEAD 2>/dev/null || echo "unknown")

if [ -f tools/agbcc/bin/agbcc ] && [ -f "$AGBCC_CACHE_FILE" ] && [ "$(cat "$AGBCC_CACHE_FILE")" = "$AGBCC_COMMIT" ]; then
    echo "agbcc is up-to-date (cached), skipping build."
else
    echo "Building agbcc..."
    cd tools/agbcc
    # build.sh may return non-zero if the agbcc_arm variant fails to compile
    # on newer compilers, but the main agbcc binary will still be built.
    ./build.sh || true
    ./install.sh ../..
    cd ../..

    # Verify agbcc was built
    if [ ! -f tools/agbcc/bin/agbcc ]; then
        echo "Error: agbcc failed to build."
        exit 1
    fi

    echo "$AGBCC_COMMIT" > "$AGBCC_CACHE_FILE"
fi

build_tool gbafix
build_tool preproc
build_tool gbadisasm
# echo ""

# if [ -f tools/gbafix/gbafix ]; then
#     echo "gbafix is up-to-date, skip build."
# else
#     echo "Building gbafix..."
#     cd tools/gbafix
#     make
#     cd ../..

#     if [ ! -f tools/gbafix/gbafix ]; then
#         echo "Error: gbafix failed to build."
#         exit 1
#     fi
# fi

# echo ""

# if [ -f tools/preproc/preproc ]; then
#     echo "preproc is up-to-date, skip build."
# else
#     echo "Building preproc..."
#     cd tools/preproc
#     make
#     cd ../..

#     if [ ! -f tools/preproc/preproc ]; then
#         echo "Error: preproc failed to build."
#         exit 1
#     fi
# fi

# echo ""

# if [ -f tools/gbadisasm/gbadisasm ]; then
#     echo "gbadisasm is up-to-date, skip build."
# else
#     echo "Building gbadisasm..."
#     cd tools/gbadisasm
#     make
#     cd ../..

#     if [ ! -f tools/gbadisasm/gbadisasm ]; then
#         echo "Error: gbadisasm failed to build."
#         exit 1
#     fi
# fi

# Set up Python venv for Luvdis
# echo ""
# echo "Setting up Python environment for Luvdis..."
# if [ ! -d .venv ]; then
#     python3 -m venv .venv
# fi
# source .venv/bin/activate
#pip install -q "setuptools<81" click click-default-group tqdm 2>/dev/null

# Generate asm/ from ROM
echo ""
echo "Generating assembly from ROM..."
tools/gbadisasm/gbadisasm baserom.gba -c ll.cfg > code.s
python3 scripts/split_asm.py

echo ""
echo "=== Setup complete ==="
echo "Run 'make' to build the ROM and verify the match."
