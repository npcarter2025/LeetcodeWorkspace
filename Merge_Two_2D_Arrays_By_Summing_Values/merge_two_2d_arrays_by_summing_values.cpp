#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> ret;
    
            map<int, int> mp;
            for (auto& x : nums1) {
                mp[x[0]] += x[1];
            }
            for (auto& x : nums2) {
                mp[x[0]] += x[1];
            }
    
            for (auto& x : mp) {
                // It should just view them as a Pair
                ret.push_back({x.first, x.second});
            }
    
            return ret;
    
        }
    };