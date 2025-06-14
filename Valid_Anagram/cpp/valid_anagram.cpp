#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        map<char, int> hash_S;
        map<char, int> hash_T;

        for (int i = 0; i < s.size(); i++) {
            hash_S[s[i]]++;
            hash_T[t[i]]++;
        }

        return hash_S == hash_T;
    }

    bool isAnagram_First_Try(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        map<char, int> hash_S;
        map<char, int> hash_T;

        for (int i = 0; i < s.size(); i++ ) {
            char elem = s[i];
            if (hash_S.count(elem)) {
                hash_S[elem] = hash_S.at(elem) + 1;
            } else {
                hash_S[elem] = 1;
            }  
        }
        for (int i = 0; i < t.size(); i++ ) {
            char elem = t[i];
            if (hash_T.count(elem)) {
                hash_T[elem] = hash_T.at(elem) + 1;
            } else {
                hash_T[elem] = 1;
            }  
        }
        return hash_S == hash_T;
    }
};
