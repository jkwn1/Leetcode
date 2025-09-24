class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> countsLeft(50001, 0);
        vector<int> countsRight(50001, 0);
        vector<long long> dpLeft(n, 0);
        vector<long long> dpRight(n, 0);
    
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 50000) dpLeft[i] = countsLeft[nums[i]];
            if (nums[i] % 2 == 0) {
                countsLeft[nums[i]/2]++;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] <= 50000) dpRight[i] = countsRight[nums[i]];
            if (nums[i] % 2 == 0) {
                countsRight[nums[i]/2]++;
            }
        }
        long long ans = 0;
        for (int i = 1; i < n-1; i++) {
            ans += dpLeft[i] * dpRight[i];
            ans %= 1000000007;
        }
        return ans;
    }
};
