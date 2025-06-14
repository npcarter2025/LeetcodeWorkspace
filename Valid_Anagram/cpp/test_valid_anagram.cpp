/* Reminder to self: use terminal
    use g++ compiler
*
*/


#include <iostream>
#include "valid_anagram.cpp"

using namespace std;

int main() {
    Solution solution;
    
    // Test case 1: Valid anagram
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Test 1: " << (solution.isAnagram(s1, t1) ? "Passed" : "Failed") << endl;
    
    // Test case 2: Invalid anagram
    string s2 = "rat";
    string t2 = "car";
    cout << "Test 2: " << (solution.isAnagram(s2, t2) ? "Passed" : "Failed") << endl;
    
    // Test case 3: Empty strings
    string s3 = "";
    string t3 = "";
    cout << "Test 3: " << (solution.isAnagram(s3, t3) ? "Passed" : "Failed") << endl;
    
    // Test case 4: Different lengths
    string s4 = "hello";
    string t4 = "world";
    cout << "Test 4: " << (solution.isAnagram(s4, t4) ? "Passed" : "Failed") << endl;
    




    // Test case 1: Valid anagram
    string s5 = "anagram";
    string t5 = "nagaram";
    cout << "Test 1: " << (solution.isAnagram_First_Try(s5, t5) ? "Passed" : "Failed") << endl;
    
    // Test case 2: Invalid anagram
    string s6 = "rat";
    string t6 = "car";
    cout << "Test 2: " << (solution.isAnagram_First_Try(s6, t6) ? "Passed" : "Failed") << endl;
    
    // Test case 3: Empty strings
    string s7 = "";
    string t7 = "";
    cout << "Test 3: " << (solution.isAnagram_First_Try(s7, t7) ? "Passed" : "Failed") << endl;
    
    // Test case 4: Different lengths
    string s8 = "hello";
    string t8 = "world";
    cout << "Test 4: " << (solution.isAnagram_First_Try(s8, t8) ? "Passed" : "Failed") << endl;
    
    return 0;
} 