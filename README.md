# LeetCode Practice Workspace

This repo contains a few of my LeetCode solutions in both **Python** and **C++**. I'll be adding to this periodically.

## 🧪 Features
- Python solutions with `unittest`
- C++ solutions with `CMake` and simple test runners
- Problem-centric organization with language subdirectories
- Easy comparison of implementations across languages

## 📁 Directory Structure
```
leetcode_workspace/
├── __cheatsheets__/     # Reference materials and cheat sheets
├── Two_Sum/
│   ├── python/          # Python solutions for two sum problem
│   └── cpp/             # C++ solutions for two sum problem
├── Basic_Calculator/
│   ├── python/          # Python Basic Calculator implementation
│   └── cpp/             # C++ Basic Calculator implementation
├── Basic_Calculator_II/
│   ├── python/          # Python Basic Calculator II implementation
│   └── cpp/             # C++ Basic Calculator II implementation
├── Basic_Calculator_III/
│   ├── python/          # Python Basic Calculator III implementation
│   └── cpp/             # C++ Basic Calculator III implementation
└── Serialize_And_Deserialize_Binary_Tree/
    ├── python/          # Python Serialize and Deserialize Binary Tree implementation
    └── cpp/             # C++ Serialize and Deserialize Binary Tree implementation
```

## 🧰 How to Run

### Python (Individual Problem Approach - Recommended)
```bash
# Work on a specific problem by navigating to its Python directory
cd Two_Sum/python
python3 two_sum_test.py

cd Basic_Calculator_II/python  
python3 basic_calculator_ii_test.py

cd Basic_Calculator_III/python
python3 basic_calculator_iii_test.py

# Add -v for verbose flag to see individual test names and descriptions
python3 basic_calculator_iii_test.py -v
```

### Python (Running Single Test Cases)
```bash
# Run a specific test method within a test file
cd Basic_Calculator_III/python
python3 -m unittest basic_calculator_iii_test.TestBasicCalculatorIII.test_example_1 -v
python3 -m unittest basic_calculator_iii_test.TestBasicCalculatorIII.test_nested_parentheses -v

# Run all tests in a specific test class
python3 -m unittest basic_calculator_iii_test.TestBasicCalculatorIII -v

# Examples for other problems:
cd Basic_Calculator_II/python
python3 -m unittest basic_calculator_ii_test.TestBasicCalculatorII.test_example_1 -v
python3 -m unittest basic_calculator_ii_test.TestBasicCalculatorII.test_precedence_edge_cases -v

cd Two_Sum/python  
python3 -m unittest two_sum_test.TestTwoSum.test_example -v

# Alternative: You can also run specific tests by line number in some IDEs or with pytest
```

### Python (Discovering Available Tests)
```bash
# List all test methods in a test file
cd Basic_Calculator_II/python
python3 -c "import basic_calculator_ii_test; [print(f'  - {method}') for method in sorted(dir(basic_calculator_ii_test.TestBasicCalculatorII)) if method.startswith('test_')]"

# Or just run with -v to see all test names as they execute
python3 basic_calculator_ii_test.py -v
```

### Python (All Tests at Once from Root)
```bash
# Run all Python tests across all problems
python3 -m unittest discover -s . -p "*test*.py"
```

### C++
```bash
# Individual problems - compile and run directly
cd Two_Sum/cpp
g++ -std=c++17 -o test test_two_sum.cpp && ./test

cd Basic_Calculator/cpp
g++ -std=c++17 -o test test_basic_calculator.cpp && ./test

cd Basic_Calculator_II/cpp
g++ -std=c++17 -o test test_basic_calculator_ii.cpp && ./test

# OR using CMake from root directory (Recommended)
mkdir -p build && cd build
cmake ..
make
./two_sum_test
./basic_calculator_test
./basic_calculator_ii_test
./basic_calculator_iii_test
```

## 🚀 Adding New Problems

### For a new problem category:
1. Create the problem directory: `mkdir New_Problem`
2. Create language subdirectories: `mkdir New_Problem/python New_Problem/cpp`
3. Add your solutions and tests in the respective language directories
4. Update `CMakeLists.txt` if adding C++ solutions

### For existing problem category:
1. Navigate to the problem directory
2. Add your solution in the appropriate language subdirectory

## 🧠 Notes
- C++ uses CMake for modern build setup from the root directory
- Python uses built-in unittest module
- Documentation and description files are typically in the Python directory
- The `__cheatsheets__/` directory contains helpful reference materials

Happy coding!