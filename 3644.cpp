class Solution {
public:
int sortPermutation(vector<int>& nums) {
    int currVal = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (i != nums[i]) {
            if (currVal == -1) {
                currVal = nums[i];
            }
            else {
                currVal = currVal & nums[i];
            }
        }
    }
    if (currVal == -1) return 0;
    return currVal;
}
};
