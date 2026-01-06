#include <vector>
#include <queue>
using namespace std;

//Non-optimized approach. I'm just doing problems that allow me to use Priority Queues to practice DSA's

class Solution {
    public:
        vector<int> numberGame(vector<int>& nums) {
            priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    
            vector<int> res;
            while (!pq.empty()) {
                int temp = pq.top();
                pq.pop();
                res.push_back(pq.top());
                pq.pop();
                res.push_back(temp);
    
            }
    
            return res;
            
        }
    };

