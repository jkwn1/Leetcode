class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (int mult = 1; mult <= 100; mult++) {
            bool poss = false;
            for (int i: nums) {
                if (i == k * mult) {
                    poss = true;
                    break;
                }
            }
            if (!poss) {
                return k * mult;
            }
        }
        return k * 101;
    }
};
