#include <string>
#include <vector>
using namespace std;
class Solution {
    public:
        string intToRoman(int num) {
            //M (1000), CM (900), D (500), CD (400), C (100), XC (90), L (50), XL (40), X (10), IX (9), V (5), IV (4), I (1).
            string result;
            vector<pair<int, string>> vec = {
                {1000, "M"},
                {900, "CM"},
                {500, "D"},
                {400, "CD"},
                {100, "C"},
                {90, "XC"},
                {50, "L"},
                {40, "XL"},
                {10, "X"},
                {9, "IX"},
                {5, "V"},
                {4, "IV"},
                {1, "I"}
            };
    
            for (auto& [k, v] : vec) {
                while (num >= k) {
                    result += v;
                    num -= k;
                }
            }
            return result;
        }
    };