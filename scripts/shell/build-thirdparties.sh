#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    $VCPKG_ROOT/vcpkg install --triplet x64-linux catch2 fmt date tl-expected
elif [[ "$OSTYPE" == "darwin"* ]]; then
    $VCPKG_ROOT/vcpkg install --triplet x64-osx catch2 fmt date tl-expected
fi
