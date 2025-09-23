class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int ind = 1;
    int prev = nums[0];
    for (int i = 1; i < (int) nums.size(); i++) {
        if (nums[i] != prev) {
            nums[ind] = nums[i];
            prev = nums[i];
            ind++;
        }
    }
    return ind;
}
};
