class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int high = 1;
        int low = 0;
        int totalProfit = 0;

        while (high < prices.size()) {
            if (prices[high]-prices[low] > 0) {
                totalProfit += prices[high]-prices[low];
            }
            high++;
            low++;
        }

        return totalProfit;
    }
};