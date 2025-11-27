#include <unordered_map>
#include <vector>
#include <limits>
#include <stdio.h>

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::unordered_map<int, std::vector<int>> hashMap;
        int maxElems = 0;

        for (int i = 0; i < nums.size(); i++) {
            int elem = nums[i];

            if (hashMap.count(elem) == 0) {

                std::vector<int> newEntry = {1, i, i};
                hashMap[elem] = newEntry;
            } else {
 
  
                hashMap[elem][0]++;
                hashMap[elem][2] = i;
            }
            maxElems = hashMap[elem][0] > maxElems ? hashMap[elem][0] : maxElems;
            
        }
        int minLength = std::numeric_limits<int>::max();

        if (maxElems == 1) {
            return maxElems;
        }
        for (auto it = hashMap.begin(); it != hashMap.end(); ++it ) {
            const std::vector<int>& values = it->second;

            if (values[0] == maxElems) {
                int currLen = values[2] - values[1] + 1;
                minLength = currLen < minLength ? currLen : minLength;
            }

        }
        return minLength;
    }
};