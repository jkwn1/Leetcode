class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int prev = 0;
        int count = 0;
        for (int k: nums) {
            if (k >= prev) {
                count++;
                prev = k;
            }
        }
        return count;
    }
};
