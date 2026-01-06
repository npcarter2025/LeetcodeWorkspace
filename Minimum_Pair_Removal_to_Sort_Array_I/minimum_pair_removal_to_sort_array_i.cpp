#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    public:
        int minimumPairRemoval(vector<int>& nums) {
    
            int moves = 0;
    
            while (check_order(nums) == false) {

                int min_val = INT_MAX;
                int curr = 1;
    
                for (int i = 1; i < nums.size(); i++ ) {
                    int value = nums[i] + nums[i-1];
                    curr = value < min_val ? i : curr;
                    min_val = value < min_val ? value : min_val;
                }
                moves++;
    
                nums[curr-1] = min_val;
                nums.erase(nums.begin() + curr);
            }
    
    
    
            return moves;
            
        }
    
        bool check_order(vector<int>& nums) {
    
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    return false;
                }
            }
    
            return true;
        }
    };

int main() {
    vector<int> tv1 = {1,2,3,4,5};
    vector<int> tv2 = {5,4,3,2,1};
    vector<int> tv3 = {1,1,4,2};

    int a1, a2, a3;

    Solution s1;

    a1 = s1.minimumPairRemoval(tv1);
    a2 = s1.minimumPairRemoval(tv2);
    a3 = s1.minimumPairRemoval(tv3);

    printf("a1 = %d\n", a1);
    printf("a2 = %d\n", a2);
    printf("a3 = %d\n", a3);


    return 0;


}