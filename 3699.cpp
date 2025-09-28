class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        vector<long long> dp(r-l+1, 1);
        long long MOD = 1e9+7;
        long long sum = (r-l) % MOD;
        for (int i = 1; i < n; i++) {
            vector<long long> newDP(r-l+1, 0);
            long long newSUM = 0;
            for (int j = 0; j < r-l; j++) {
                newDP[j] = sum;
                newSUM = (newSUM + sum) % MOD;
                sum = (sum - dp[r-l-1-j]) % MOD;
            }
            sum = newSUM;
            dp = newDP;
        }
        int ans = (int) ((sum * 2) % MOD);
        if (ans < 0) ans += MOD;
        return ans;
    }
};
