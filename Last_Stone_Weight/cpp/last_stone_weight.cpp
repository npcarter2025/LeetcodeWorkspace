#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() >= 2) {
            int stone1 = pq.top(); pq.pop();
            int stone2 = pq.top(); pq.pop();

            if (stone1 != stone2) {
                pq.push(stone1 - stone2);
            }

        }
        if (pq.size() == 0) {
            return 0;
        }
        int result = pq.top();
        return result;

    }
};