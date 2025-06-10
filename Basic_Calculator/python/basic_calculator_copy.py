def calculate(s):
    """
    Evaluate a mathematical expression string without using eval().
    
    Args:
        s (str): A string representing a valid mathematical expression
        
    Returns:
        int: The result of the evaluation
    """
    stack = []
    num = 0
    sign = 1  # 1 for positive, -1 for negative
    result = 0
    
    for char in s:
        if char.isdigit():
            # Build the current number
            num = num * 10 + int(char)
        elif char == '+':
            # Add the current number to result and reset
            result += sign * num
            num = 0
            sign = 1
        elif char == '-':
            # Add the current number to result and set negative sign
            result += sign * num
            num = 0
            sign = -1
        elif char == '(':
            # Push current result and sign to stack, reset for new scope
            stack.append(result)
            stack.append(sign)
            result = 0
            sign = 1
        elif char == ')':
            # Add current number, then pop sign and previous result
            result += sign * num
            num = 0
            result *= stack.pop()  # multiply by sign before parentheses
            result += stack.pop()  # add result before parentheses
        # Skip spaces
    
    # Add the last number
    result += sign * num
    return result 