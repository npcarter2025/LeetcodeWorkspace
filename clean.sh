#!/bin/bash

echo "🧹 Cleaning up LeetCode workspace..."

# Remove Python cache directories and compiled files
echo "📁 Removing Python cache files..."
find . -name "__pycache__" -type d -exec rm -rf {} + 2>/dev/null
find . -name "*.pyc" -delete 2>/dev/null

# Remove compiled C++ executables
echo "⚙️ Removing compiled C++ executables..."
find . -name "test" -type f -delete 2>/dev/null
find . -name "*.out" -delete 2>/dev/null
find . -name "a.out" -delete 2>/dev/null

# Clean CMake build directory
echo "🏗️ Cleaning build directory..."
if [ -d "build" ]; then
    rm -rf build/*
fi

# Remove macOS system files (optional)
echo "🍎 Removing .DS_Store files..."
find . -name ".DS_Store" -delete 2>/dev/null

echo "✅ Cleanup complete!"
echo ""
echo "What was cleaned:"
echo "  - Python __pycache__ directories"
echo "  - Python .pyc files"
echo "  - Compiled C++ executables"
echo "  - CMake build artifacts"
echo "  - macOS .DS_Store files" 