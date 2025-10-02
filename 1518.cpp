class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int change = numBottles / numExchange;
            ans += change;
            numBottles -= (numExchange-1) * change;
        }
        return ans;
    }
};
