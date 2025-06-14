class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        hash_s = {}
        hash_t = {}

        for elem in s:
            hash_s[elem] = hash_s.get(elem, 0) + 1
        
        for elem in t:
            hash_t[elem] = hash_t.get(elem, 0) + 1

        return hash_s == hash_t