class Solution {
public:
    long long exp(long long x, long long n, long long m) {
        long long res = 1;
        while (n > 0) {
            if (n % 2 == 1) res = res * x % m;
            x = x * x % m;
            n /= 2;
        }
        return res;
    }
    int countStableSubsequences(vector<int>& nums) {
        long long MOD = 1e9+7;
        vector<vector<long long>> dpE(nums.size(), vector<long long>(3, 0));
        vector<vector<long long>> dpO(nums.size(), vector<long long>(3, 0));
        // dp[i][j] is after i, how many end with j consecutive
        long long ans = 0;
        dpE[0][0] = 1;
        dpO[0][0] = 1;
        if (nums[0] % 2 == 0) {
            dpE[0][1] = 1;
            dpO[0][0] = 2;
        }
        else {
            dpO[0][1] = 1;
            dpE[0][0] = 2;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                dpE[i][0] = dpE[i-1][0];
                dpE[i][1] = (dpE[i-1][0] + dpE[i-1][1]) % MOD;
                dpE[i][2] = (dpE[i-1][1] + dpE[i-1][2]) % MOD;
                long long addition = dpE[i-1][2] * exp(2, nums.size()-i-1, MOD) % MOD;
                ans = (ans + addition) % MOD;
                dpO[i][0] = (dpE[i][1]+dpE[i][2]+1) % MOD;
                dpO[i][1] = dpO[i-1][1];
                dpO[i][2] = dpO[i-1][2];
            }
            else {
                dpO[i][0] = dpO[i-1][0];
                dpO[i][1] = (dpO[i-1][0] + dpO[i-1][1]) % MOD;
                dpO[i][2] = (dpO[i-1][1] + dpO[i-1][2]) % MOD;
                long long addition = dpO[i-1][2] * exp(2, nums.size()-i-1, MOD) % MOD;
                ans = (ans + addition) % MOD;
                dpE[i][0] = (dpO[i][1]+dpO[i][2]+1) % MOD;
                dpE[i][1] = dpE[i-1][1];
                dpE[i][2] = dpE[i-1][2];
            }
        }
        ans = (exp(2, nums.size(), MOD)-ans-1) % MOD;
        if (ans < 0) {
            ans += MOD;
        }
        return ans;
    }
};
