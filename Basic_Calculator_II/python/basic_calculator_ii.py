def calculate(s):
    """
    Evaluate a mathematical expression string with +, -, *, / operators.
    
    Args:
        s (str): A string representing a valid mathematical expression
                with integers and operators (+, -, *, /) separated by spaces
        
    Returns:
        int: The result of the evaluation
        
    Note:
        - Integer division should truncate toward zero
        - No parentheses in this version
        - Operator precedence: * and / before + and -
        - All input numbers are non-negative
    """
    # TODO: Implement the solution
    # Hint: Use a stack to handle operator precedence
    # Process * and / immediately, defer + and - to stack
    pass 


    stack = []
    temp = s
    index = 0
    values = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    
    result = 0
    current_operator = "+"  # Start with implicit +

    while index < len(temp):
        while index < len(temp) and temp[index] == " ":
            index += 1

        # Read number
        digits = 0
        while index < len(temp) and temp[index] in values:
            digits = digits * 10 + int(temp[index])
            index += 1

        # Handle *, /
        while index < len(temp) and temp[index] == " ":
            index += 1

        while index < len(temp) and temp[index] in "*/":
            op = temp[index]
            index += 1
            while index < len(temp) and temp[index] == " ":
                index += 1
            b = 0
            while index < len(temp) and temp[index] in values:
                b = b * 10 + int(temp[index])
                index += 1
            if op == "*":
                digits *= b
            else:
                digits = int(digits / b)  # truncate toward zero

            while index < len(temp) and temp[index] == " ":
                index += 1

        # Now apply + or - with the result of the above
        if current_operator == "+":
            stack.append(digits)
        elif current_operator == "-":
            stack.append(-digits)

        # Read next operator
        if index < len(temp):
            current_operator = temp[index]
            index += 1

    return sum(stack)



