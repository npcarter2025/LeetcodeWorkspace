#include <string>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> stk;
    int num = 0;
    int sign = 1;  // 1 for positive, -1 for negative
    int result = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            // Build the current number
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            // Add the current number to result and reset
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            // Add the current number to result and set negative sign
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            // Push current result and sign to stack, reset for new scope
            stk.push(result);
            stk.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            // Add current number, then pop sign and previous result
            result += sign * num;
            num = 0;
            result *= stk.top(); stk.pop();  // multiply by sign before parentheses
            result += stk.top(); stk.pop();  // add result before parentheses
        }
        // Skip spaces automatically
    }
    
    // Add the last number
    result += sign * num;
    return result;
} 