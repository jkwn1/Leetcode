class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums2(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            nums2[i] = {nums[i], i};
        }
        sort(nums2.begin(), nums2.end());
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            if (nums2[start].first + nums2[end].first == target) {
                return {nums2[start].second, nums2[end].second};
            }
            if (nums2[start].first + nums2[end].first > target) {
                end--;
            }
            if (nums2[start].first + nums2[end].first < target) {
                start++;
            }
        }
        return {-1, -1};
    }
};
