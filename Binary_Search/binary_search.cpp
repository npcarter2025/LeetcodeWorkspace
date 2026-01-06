#include <vector>
using namespace std;

class Solution {
    public:
        static int search(vector<int>& nums, int target) {
            int left, right, mid;
            left = 0;
            right = nums.size() - 1;
            while (left <= right) {
                mid = (left + (right-left)/2);
                //printf("mid: %d\n", mid);
                if (nums[mid] == target) return mid;
                
                // [1,2,3,4,5]
                if (nums[mid] > target) right = mid-1;
    
    
                else if (nums[mid] < target) left=mid+1;
    
            }
            return -1;
        }
    };

int main() {


    vector<int> tv1 = {1,2,4,7,32};
    vector<int> tv2 = {-1,4,29,53,777,7777,123412,1341234};

    int a1 = Solution::search(tv1, 32);

    int a2 = Solution::search(tv2, -1);
    int a3 = Solution::search(tv2, 5);

    printf("a1: %d\na2: %d\na3: %d\n", a1, a2, a3);

    return 0;
    
}