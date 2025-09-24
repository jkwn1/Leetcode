class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(60001, 0);
        for (int i: nums) {
            count[i+30000] = (count[i+30000]+1) % 2;
        }
        for (int i = 0; i <= 60000; i++) {
            if (count[i] == 1) {
                return i - 30000;
            }
        }
        return -1;
    }
};
