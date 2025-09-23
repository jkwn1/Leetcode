class Solution {
public:
    bool is1Smaller(vector<int> v1, vector<int> v2) {
    int n = v1.size();
    for (int i = 0; i < n; i++) {
        if (v1[i] < v2[i]) {
            return true;
        }
        if (v1[i] > v2[i]) {
            return false;
        }
    }
    return true;
}
vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
    int n = nums.size();
    int maxBit = 1<<(n);
    vector<vector<vector<int>>> dp(maxBit, vector<vector<int>>(k));
    vector<int> size(n);
    for (int i = 0; i < n; i++) {
        dp[1<<i][nums[i] % k] = {nums[i]};
        if (nums[i] >= 100000) size[i] = 1000000%k;
        else if (nums[i] >= 10000) size[i] = 100000%k;
        else if (nums[i] >= 1000) size[i] = 10000%k;
        else if (nums[i] >= 100) size[i] = 1000%k;
        else if (nums[i] >= 10) size[i] = 100%k;
        else if (nums[i] >= 1) size[i] = 10%k;
    }

    for (int bit = 1; bit < maxBit; bit++) {
        for (int i = 0; i < n; i++) {
            if ((bit & (1<<i)) != 0) {
                int prev = bit - (1<<i);
                for (int j = 0; j < k; j++) {
                    if (dp[prev][j].size() > 0) {
                        int newMod = (j * size[i] + nums[i]) % k;
                        vector<int> newVec = dp[prev][j];
                        newVec.push_back(nums[i]);
                        if (dp[bit][newMod].size() > 0) {
                            if (is1Smaller(newVec, dp[bit][newMod])) dp[bit][newMod] = newVec;
                        }
                        else {
                            dp[bit][newMod] = newVec;
                        }
                    }
                }
            }
        }
    }
    return dp[maxBit-1][0];
}
};
