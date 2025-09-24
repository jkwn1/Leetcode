class Solution {
public:
long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    long long currMax = 0;
    for (int i = 0; i < prices.size(); i++) {
        currMax += prices[i] * strategy[i];
    }
    long long currProfit = currMax;
    for (int i = 0; i < k; i++) {
        if (i < k / 2) {
            currProfit -= prices[i] * strategy[i];
        }
        else {
            currProfit -= prices[i] * (strategy[i] - 1);
        }
    }
    currMax = max(currMax, currProfit);
    for (int start = 1; start < prices.size() - k+1; start++) {
        currProfit += prices[start-1] * (strategy[start-1]);
        currProfit -= prices[start - 1 + k/2];
        currProfit -= prices[start+k-1] * (strategy[start+k-1] - 1);
        currMax = max(currMax, currProfit);
    }
    return currMax;
}
};
