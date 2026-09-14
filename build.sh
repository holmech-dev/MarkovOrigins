#!/bin/bash

# Configure the build tree in ./build, ensure CMake is reachable
echo "🔧 Configuring with CMAKE..."
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
if [ $? -ne 0 ]; then
    echo "❌ CMake configuration failed"
    exit 1
fi

# Compile and link main.cpp
echo "🔧 Compiling main.cpp with g++ and linking..."
cmake --build build --config Release
if [ $? -ne 0 ]; then
    echo "❌ Failed to compile and link main.cpp"
    exit 1
fi
echo "✅ Build successful! Run with ./MarkovOrigins "
