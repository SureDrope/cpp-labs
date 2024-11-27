#!/usr/bin/bash

set -euo pipefail

mkdir -p build

/usr/bin/qmake6 -o build project/lab_7.pro

cd build

make
