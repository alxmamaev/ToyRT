#!/bin/bash

BUILD_DIR="build"
INCLUDE_DIR="include"
SRC_DIR="src"

mkdir -p "$BUILD_DIR"

BUILD_FILES="$SRC_DIR/main.cpp $SRC_DIR/network.cpp $SRC_DIR/builder.cpp $SRC_DIR/tensor.cpp $SRC_DIR/layers/abstract.cpp $SRC_DIR/layers/linear.cpp $SRC_DIR/layers/relu.cpp"

g++ -I $INCLUDE_DIR $BUILD_FILES -o $BUILD_DIR/main