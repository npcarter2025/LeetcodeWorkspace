#include <string>
#include <stack>
#include <cctype>


class Solution {
public:
    string decodeString(string s) {
        stack<string>  strStack;
        stack<int> numStack;

        string curr_str = "";
        int num = 0;

        for (int i = 0; i < s.length(); i++ ){
            if (isdigit(s[i])) {
                num = num * 10 + (int(s[i])-'0'); 
            }
            else if ((s[i]) == '[') {
                strStack.push(curr_str);
                numStack.push(num);
                curr_str = "";
                num = 0;
            }
            else if (s[i] == ']') {
                int repeat = numStack.top(); // return by reference
                numStack.pop();

                string prev_str = strStack.top();
                strStack.pop();

                string temp = "";
                for (int j = 0; j < repeat; j++) {
                    temp += curr_str;
                }
                curr_str = prev_str + temp;
            }
            else {
                curr_str += s[i];
            }
        }
        return curr_str;
    }
};
