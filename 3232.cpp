class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int doublesum = 0;
        int singlesum = 0;
        int totalsum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 10) {
                singlesum += nums[i];
            }
            else if (nums[i] < 100) {
                doublesum += nums[i];
            }
            totalsum += nums[i];
        }
        return (singlesum*2 > totalsum) || (doublesum*2 > totalsum);
    }
};
