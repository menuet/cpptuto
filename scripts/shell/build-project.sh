#!/bin/bash

mkdir -p ./out/build/lin

pushd ./out/build/lin

cmake -DCMAKE_VERBOSE_MAKEFILE=TRUE ../../..

cmake --build . --config Debug

popd
