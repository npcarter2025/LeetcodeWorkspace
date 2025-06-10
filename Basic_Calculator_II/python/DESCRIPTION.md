# 227. Basic Calculator II

**Difficulty:** Medium  
**Topics:** Math, String, Stack  
**Companies:** Facebook, Microsoft, Google

## Problem Description

Given a string `s` which represents an expression, *evaluate this expression and return its value*.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of `[-2^31, 2^31 - 1]`.

**Note:** You are **not** allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

## Examples

### Example 1:
```
Input: s = "3+2*2"
Output: 7
```

### Example 2:
```
Input: s = " 3/2 "
Output: 1
```

### Example 3:
```
Input: s = " 3+5 / 2 "
Output: 5
```

## Constraints:

- `1 <= s.length <= 3 * 10^5`
- `s` consists of integers and operators `('+', '-', '*', '/')` separated by some number of spaces.
- `s` represents **a valid expression**.
- All the integers in the expression are non-negative integers in the range `[0, 2^31 - 1]`.
- The answer is **guaranteed** to fit in a **32-bit integer**.

## Key Points:

1. **Operator Precedence**: `*` and `/` have higher precedence than `+` and `-`
2. **Integer Division**: Division truncates toward zero (e.g., `7/3 = 2`, `-7/3 = -2`)
3. **No Parentheses**: Unlike Basic Calculator I, this version has no parentheses
4. **Space Handling**: Expression may contain spaces that should be ignored
5. **Non-negative Numbers**: All numbers in the input are non-negative

## Approach Hints:

1. Use a stack to handle operator precedence
2. Process numbers and operators sequentially
3. Handle `*` and `/` immediately when encountered
4. Handle `+` and `-` by pushing to stack for later processing
5. Sum up the stack at the end

---

## 🧪 How to Test Your Solution

### Run All Tests
```bash
python3 basic_calculator_ii_test.py -v
```

### Run a Single Test Case
```bash
# Example: Run just the first example
python3 -m unittest basic_calculator_ii_test.TestBasicCalculatorII.test_example_1 -v

# Example: Run just the precedence tests
python3 -m unittest basic_calculator_ii_test.TestBasicCalculatorII.test_multiplication_precedence -v

# Example: Run division truncation tests
python3 -m unittest basic_calculator_ii_test.TestBasicCalculatorII.test_division_truncation -v
```

### Discover Available Tests
```bash
# List all available test methods
python3 -c "import basic_calculator_ii_test; [print(f'  - {method}') for method in sorted(dir(basic_calculator_ii_test.TestBasicCalculatorII)) if method.startswith('test_')]"
```

### Quick Manual Test
```bash
python3 -c "from basic_calculator_ii import calculate; print(calculate('3+2*2'))"
``` 