class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        std::stack<int> prev_seen;
        std::vector<int> result;
        std::stack<int> pre_process;
        std::vector<int> post_processed;
        for (int i = prices.size()-1; i >= 0; i--) {

            while (!prev_seen.empty() && prices[i] < prev_seen.top()) {
                prev_seen.pop();
            }
            if (prev_seen.empty()) {
                pre_process.push(prices[i]);
            } else {
                pre_process.push(prices[i] - prev_seen.top());

            }
            prev_seen.push(prices[i]);
        }

        while (!pre_process.empty()) {
            post_processed.push_back(pre_process.top());
            pre_process.pop();
        }
        return post_processed;
    }
};