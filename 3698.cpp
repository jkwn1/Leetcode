class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        int peak = n-1;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] >= nums[i+1]) {
                peak = i;
                break;
            }
        }
        for (int i = peak+1; i < n-1; i++) {
            if (nums[i] <= nums[i+1]) {
                return -1;
            }
        }
        long long frontSum = 0;
        for (int i = 0; i < peak; i++) {
            frontSum += nums[i];
        }
        long long backSum = 0;
        for (int i = peak+1; i < n; i++) {
            backSum += nums[i];
        }
        return min(abs(frontSum-backSum-nums[peak]), abs(backSum-frontSum-nums[peak]));
    }
};
