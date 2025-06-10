def calculate(s):
    """
    Evaluate a mathematical expression string with +, -, *, / operators and parentheses.
    
    Args:
        s (str): A string representing a valid mathematical expression
                with integers, operators (+, -, *, /), parentheses, and spaces
        
    Returns:
        int: The result of the evaluation
        
    Note:
        - Integer division should truncate toward zero
        - Supports parentheses for grouping expressions
        - Operator precedence: * and / before + and -, parentheses override precedence
        - All input numbers are non-negative
        - Expression is guaranteed to be valid
    """
    def helper(s, index):
        """
        Helper function that processes expression from given index.
        Returns (result, next_index)
        """
        stack = []
        num = 0
        operator = '+'  # Start with implicit +
        
        while index < len(s):
            char = s[index]
            
            if char.isdigit():
                num = num * 10 + int(char)
            elif char == '(':
                # Recursively evaluate the expression in parentheses
                num, index = helper(s, index + 1)
            elif char in '+-*/':
                # Process the current number with the previous operator
                if operator == '+':
                    stack.append(num)
                elif operator == '-':
                    stack.append(-num)
                elif operator == '*':
                    stack.append(stack.pop() * num)
                elif operator == '/':
                    # Handle truncation toward zero for all cases
                    last = stack.pop()
                    stack.append(int(last / num))
                
                operator = char
                num = 0
            elif char == ')':
                # End of parentheses - process final number and return
                if operator == '+':
                    stack.append(num)
                elif operator == '-':
                    stack.append(-num)
                elif operator == '*':
                    stack.append(stack.pop() * num)
                elif operator == '/':
                    last = stack.pop()
                    stack.append(int(last / num))
                total = 0
                for elem in stack:
                    total += int(elem)
                return total, index
            
            index += 1
        
        # Process the final number
        if operator == '+':
            stack.append(num)
        elif operator == '-':
            stack.append(-num)
        elif operator == '*':
            stack.append(stack.pop() * num)
        elif operator == '/':
            last = stack.pop()
            stack.append(int(last / num))
        total = 0
        for elem in stack:
            total += int(elem)
        return total, index

    
    # Remove spaces and call helper
    s = s.replace(' ', '')
    result, _ = helper(s, 0)
    return result

