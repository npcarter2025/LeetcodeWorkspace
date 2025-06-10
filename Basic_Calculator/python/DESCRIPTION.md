# 224. Basic Calculator

**Difficulty:** Hard  
**Topics:** Math, String, Stack  
**Companies:** Google, Facebook, Microsoft

## Problem Description

Given a string `s` representing a valid expression, implement a basic calculator to evaluate it, and return *the result of the evaluation*.

**Note:** You are **not** allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

## Examples

### Example 1:
```
Input: s = "1 + 1"
Output: 2
```

### Example 2:
```
Input: s = " 2-1 + 2 "
Output: 3
```

### Example 3:
```
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
```

## Constraints:

- `1 <= s.length <= 3 * 10^5`
- `s` consists of digits, `'+'`, `'-'`, `'('`, `')'`, and `' '`.
- `s` represents a valid expression.
- `'+'` is **not** used as a unary operation (i.e., `"+1"` and `"+(2 + 3)"` is invalid).
- `'-'` **could** be used as a unary operation (i.e., `"-1"` and `"-(2 + 3)"` is valid).
- There will be no two consecutive operators in the input.
- Every number and running calculation will fit in a signed 32-bit integer.

## Approach Hints:

1. Use a stack to handle parentheses
2. Keep track of the current number being parsed
3. Handle signs appropriately
4. Process operators when encountering them or closing parentheses

---

## 🧪 How to Test Your Solution

### Run All Tests
```bash
python3 basic_calculator_test.py -v
```

### Run a Single Test Case
```bash
# Example: Run just the first example
python3 -m unittest basic_calculator_test.TestBasicCalculator.test_example_1 -v

# Example: Run just the complex nested test
python3 -m unittest basic_calculator_test.TestBasicCalculator.test_complex_nested_expression -v
```

### Discover Available Tests
```bash
# List all available test methods
python3 -c "import basic_calculator_test; [print(f'  - {method}') for method in sorted(dir(basic_calculator_test.TestBasicCalculator)) if method.startswith('test_')]"
```

### Quick Manual Test
```bash
python3 -c "from basic_calculator import calculate; print(calculate('(1+(4+5+2)-3)+(6+8)'))"
```
