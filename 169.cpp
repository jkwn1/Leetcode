class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int) nums.size();
        map<int, int> m;
        int maxCount = 1;
        int maxNum = nums[0];
        for (int i: nums) {
            if (m.contains(i)) {
                m[i]++;
                if (m[i] > maxCount) {
                    maxCount = m[i];
                    maxNum = i;
                }
            }
            else m.insert({i, 1});
        }
        return maxNum;
    }
};
