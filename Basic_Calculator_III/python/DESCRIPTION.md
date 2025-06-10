# 772. Basic Calculator III

**Difficulty:** Hard  
**Topics:** Math, String, Stack, Recursion  
**Companies:** Google, Facebook, Microsoft

## Problem Description

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open `(` and closing parentheses `)`, the plus `+` or minus sign `-`, **non-negative** integers and empty spaces ` `.

The expression string contains only non-negative integers, `+`, `-`, `*`, `/` operators, open `(` and closing parentheses `)` and empty spaces ` `. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of `[-2147483648, 2147483647]`.

## Examples

### Example 1:
```
Input: s = "1 + 1"
Output: 2
```

### Example 2:
```
Input: s = " 6-4 / 2 "
Output: 4
```

### Example 3:
```
Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21
```

### Example 4:
```
Input: s = "(2+6* 3+5- (3*14/7+2)*5)+3"
Output: -12
```

## Constraints:

- `1 <= s.length <= 3 * 10^4`
- `s` consists of digits, `'+'`, `'-'`, `'*'`, `'/'`, `'('`, `')'`, and `' '`.
- `s` represents a valid expression.
- All the integers in the expression are non-negative integers in the range `[0, 2^31 - 1]`.
- The answer is **guaranteed** to fit in a **32-bit integer**.

## Key Features:

1. **All Four Operations**: Supports `+`, `-`, `*`, `/`
2. **Operator Precedence**: `*` and `/` have higher precedence than `+` and `-`
3. **Parentheses**: Supports nested parentheses for grouping expressions
4. **Integer Division**: Division truncates toward zero
5. **Space Handling**: Expression may contain spaces that should be ignored
6. **Non-negative Numbers**: All numbers in the input are non-negative

**Note:** Do not use the `eval()` built-in library function.

---

<details>
<summary><strong>💡 Approach Hints</strong></summary>

### Possible Approaches:

1. **Recursive Descent Parsing**: Parse expressions recursively, handling precedence naturally
2. **Stack-based with Parentheses Handling**: Extend Calculator II approach with stack for parentheses
3. **Two-Stack Method**: One stack for operands, one for operators
4. **Convert to Postfix**: Convert infix to postfix notation, then evaluate

### Key Considerations:
- Handle operator precedence: `*`, `/` before `+`, `-`
- Parentheses override normal precedence
- Need to handle nested parentheses properly
- Space characters should be ignored
- Division must truncate toward zero

</details>

<details>
<summary><strong>🔍 Algorithm Strategy</strong></summary>

### Stack-Based Approach:
1. **Parse numbers** while skipping spaces
2. **Handle operators** based on precedence
3. **Use stack for parentheses** - push current state when `(` encountered
4. **Pop stack when `)` encountered** and combine results
5. **Process high-precedence ops** (`*`, `/`) immediately
6. **Defer low-precedence ops** (`+`, `-`) to stack

### Recursive Approach:
1. **Parse expressions** recursively
2. **Handle precedence** through recursive calls
3. **Base case**: numbers and parenthesized expressions
4. **Recursive case**: operator precedence levels

</details>

<details>
<summary><strong>🧪 Test Case Breakdown</strong></summary>

### Example Analysis:

**Example 3**: `"2*(5+5*2)/3+(6/2+8)" = 21`
- Step 1: `5+5*2` = `5+10` = `15`
- Step 2: `2*15` = `30`
- Step 3: `30/3` = `10`
- Step 4: `6/2+8` = `3+8` = `11`
- Step 5: `10+11` = `21`

**Example 4**: `"(2+6* 3+5- (3*14/7+2)*5)+3" = -12`
- Inner: `3*14/7+2` = `6+2` = `8`
- Then: `8*5` = `40`
- Main: `2+6*3+5-40` = `2+18+5-40` = `25-40` = `-15`
- Final: `-15+3` = `-12`

</details>

<details>
<summary><strong>⚠️ Common Pitfalls</strong></summary>

### Watch Out For:
1. **Division truncation**: `7/3 = 2`, not `2.33...`
2. **Operator precedence**: `2+3*4 = 14`, not `20`
3. **Parentheses precedence**: `(2+3)*4 = 20`, not `14`
4. **Nested parentheses**: Handle multiple levels correctly
5. **Space handling**: Ignore all whitespace characters
6. **Edge cases**: Single numbers, zero operations, large expressions

### Debugging Tips:
- Test each precedence level separately
- Verify parentheses matching
- Check division truncation behavior
- Test with and without spaces

</details>

<details>
<summary><strong>🚀 Complexity Analysis</strong></summary>

### Time Complexity:
- **Stack-based**: O(n) - single pass through string
- **Recursive**: O(n) - each character processed once

### Space Complexity:
- **Stack-based**: O(n) - stack depth proportional to nesting
- **Recursive**: O(n) - recursion depth + stack space

### Optimization Notes:
- Both approaches are efficient for this problem size
- Choose based on implementation preference
- Stack-based might be slightly more memory efficient

</details>

---

## 🧪 How to Test Your Solution

### Run All Tests
```bash
python3 basic_calculator_iii_test.py -v
```

### Run a Single Test Case
```bash
# Example: Run just the first example
python3 -m unittest basic_calculator_iii_test.TestBasicCalculatorIII.test_example_1 -v

# Example: Run just the complex nested tests
python3 -m unittest basic_calculator_iii_test.TestBasicCalculatorIII.test_complex_nested_expressions -v

# Example: Run precedence with parentheses tests
python3 -m unittest basic_calculator_iii_test.TestBasicCalculatorIII.test_precedence_with_parentheses -v

# Example: Run deeply nested parentheses tests
python3 -m unittest basic_calculator_iii_test.TestBasicCalculatorIII.test_deeply_nested -v
```

### Discover Available Tests
```bash
# List all available test methods
python3 -c "import basic_calculator_iii_test; [print(f'  - {method}') for method in sorted(dir(basic_calculator_iii_test.TestBasicCalculatorIII)) if method.startswith('test_')]"
```

### Quick Manual Test
```bash
python3 -c "from basic_calculator_iii import calculate; print(calculate('2*(5+5*2)/3+(6/2+8)'))"
``` 