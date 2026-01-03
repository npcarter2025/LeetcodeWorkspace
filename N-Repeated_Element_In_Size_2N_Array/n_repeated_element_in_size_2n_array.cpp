
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <unordered_map>

using namespace std;

class Solution { 
    public: 
    static int repeatedNTimes(vector<int>& nums) { 
        int n = nums.size() / 2; 
        std::unordered_map<int, int> map; 
        for (int i : nums) { 
            map[i]++; 

        } 
        for (auto& i : map) { 
            if (i.second == n) { 
                return i.first; 
            } 
        } 
        return 0; 
    } 
};

int main(int argc, char* argv[]) {

    std::vector<int> vec1, v2, v3, v4;
    vec1 = {1,2,3,4,2,2,2,1};
    v2 = {1,2,3,3};
    v3 = {2,1,2,5,3,2};
    v4 = {5,1,5,2,5,3,5,4};

    Solution s1;

    int result = s1.repeatedNTimes(vec1);

    printf("result == %d\n\n", result);

    int r2 = Solution::repeatedNTimes(v2);
    printf("result == %d\n\n", r2);

    int r3 = Solution::repeatedNTimes(v3);
    printf("result == %d\n\n", r3);

    int r4 = Solution::repeatedNTimes(v4);
    printf("result == %d\n\n", r4);
    return 0;

}