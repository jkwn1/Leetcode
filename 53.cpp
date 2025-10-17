class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> prefSum(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefSum[i+1] = prefSum[i] + nums[i];
        }
        int currMin = 0;
        int ans = nums[0];
        for (int i = 1; i <= n; i++) {
            ans = max(ans, prefSum[i] - currMin);
            currMin = min(currMin, prefSum[i]);
        }
        return ans;
    }
};
