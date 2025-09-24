class Solution {
public:
long long minArraySum(vector<int>& nums, int k) {
    vector<long long> modMin(k, 1e12);
    modMin[0] = 0;
    vector<long long> dp(nums.size()+1, 0);
    dp[0] = 0;
    int currMod = 0;
    for (int i = 1; i <= nums.size(); i++) {
        currMod += nums[i-1];
        currMod %= k;
        if (modMin[currMod] < dp[i-1] + nums[i-1]) {
            dp[i] = modMin[currMod];
        }
        else {
            dp[i] = dp[i-1] + nums[i-1];
            modMin[currMod] = dp[i];
        }
    }
    return dp[nums.size()];
}
};
