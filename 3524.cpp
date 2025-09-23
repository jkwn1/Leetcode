class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);

        vector<long long> open(k, 0);
        for (int j: nums) {

            int rem = j % k;
            vector<long long> newOpen(k, 0);
            for (int i = 0; i < k; i++) {
                newOpen[(i * rem) % k] += open[i];
            }
            newOpen[rem]++;
            for (int i = 0; i < k; i++) {
                dp[i] += newOpen[i];
                open[i] = newOpen[i];
            }
        }
        return dp;
    }
};
