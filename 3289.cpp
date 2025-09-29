class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> exists(n, false);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (exists[nums[i]]) ans.push_back(nums[i]);
            else exists[nums[i]] = true;
        }
        return ans;
    }
};
