#include <string>
using namespace std; 

class Solution {
public:
    string reversePrefix(string word, char ch) {

        int index = 0;
        for (char& elem : word) {
            if (elem == ch) {
                break;
            }
            index++;
        }

        if (index == word.length()) {
            return word;
        }

        for (int i = 0; i < (index / 2) + 1; i++) {
            char temp = word[i];
            word[i] = word[index - i];
            word[index - i] = temp;
        }

        return word;
    }
};