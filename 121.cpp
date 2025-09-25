class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = prices[0];
        int maxP = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxP = max(maxP, prices[i] - smallest);
            smallest = min(smallest, prices[i]);
        }
        return maxP;
    }
};
