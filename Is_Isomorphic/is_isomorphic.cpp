#include <string>
#include <unordered_map>
#include <cstdlib>
#include <set>

using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            std::unordered_map<string, char> mappings;
            
            // Approach: add the mappings as we proceed through the string.
            // If a key exists, and its value is different, then return False
            // else, add it to the hashmap.
            // if you reach the end, return True
    
            // s = "paper", t = "title"
            // key, value = s[i], t[i]
    
            for (int i = 0; i < s.size(); i++) {
                string srcS(1, s[i]);
                srcS += 's';
                // string src(2, s[i]+"s");
    
                string srcT(1, t[i]);
                srcT += 't';
    
                if (mappings.contains(srcS) || mappings.contains(srcT)) {
                    if (mappings[srcS] != t[i] || mappings[srcT]!= s[i]) {
                        return false;
                    }
                } else {
                    mappings[srcS] = t[i];
                    mappings[srcT] = s[i];
    
                }
            }
    
            return true;
        }


        // Different way to solve with a set;

        bool isIsomorphic2(string s, string t) {
            std::unordered_map<char, char> mappings;
            std::set<char> used;
            
            // Approach: add the mappings as we proceed through the string.
            // If a key exists, and its value is different, then return False
            // else, add it to the hashmap.
            // if you reach the end, return True
    
            // s = "paper", t = "title"
            // key, value = s[i], t[i]
    
    
            // {key, value} = {char, vector of indices}
            for (int i = 0; i < s.size(); i++) {
                if (mappings.find(s[i]) != mappings.end()) {
                    if (mappings[s[i]] != t[i]) {
                        return false;
                    }
                } else {
                    if (used.contains(t[i])) {
                        return false;
                    } else {
                        mappings[s[i]] = t[i];
                        used.insert(t[i]);
    
                    }
    
    
                }
            }
    
    
    
    
            return true;
        }
    };