class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;
        bool allX = true;
        for (int i = 0; i < n; i++) {
            xorSum ^= nums[i];
            if (nums[i] != 0) allX = false;
        }
        if (allX) return 0;
        if (xorSum == 0) return n-1;
        return n;
    }
};
