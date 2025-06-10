def calculate(s):
    """
    Evaluate a mathematical expression string without using eval().
    
    Args:
        s (str): A string representing a valid mathematical expression
        
    Returns:
        int: The result of the evaluation
    """
    # need a stack
    # get rid of spaces first
    if not s:
        return 0
    sflat = s.replace(' ', '')


    #(1+(4+5+2)-3)
    # what we want is to get the evaluate numbers that are inside parentheses first.
    # I am debating about how to process nested parentheses.  
    # I have a feeling I need recursion. I am wanting to make a global stack where 
    # I put the string after I have remove all the spaces. 
    # Then I am going to process left to right

    def calc(s: str, index: int) -> (int, int):
        stack = []
        num = 0
        sign = 1
        localTotal = 0

        while index < len(s):
            char = s[index]
            if char.isdigit():
                num = num * 10 + int(char)
            elif char in '+-':
                stack.append(sign * num)
                num = 0
                if char == '+':
                    sign = 1
                else:
                    sign = -1
            elif char == '(':
                num, index = calc(s, index + 1)
            elif char == ')':
                stack.append(sign * num)
                for elem in stack:
                    localTotal += int(elem)
                return localTotal, index
            index += 1
        stack.append(sign * num)
        localTotal = 0
        for elem in stack:
            localTotal += int(elem)
        return localTotal, index
    
    total, empty = calc(sflat, 0)
    return total


