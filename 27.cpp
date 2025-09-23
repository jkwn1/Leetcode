class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> newNums;
        for (int j: nums) {
            if (j != val) {
                newNums.push_back(j);
            }
        }
        sort(newNums.begin(), newNums.end());
        nums = newNums;
        return (int) newNums.size();
    }
};
