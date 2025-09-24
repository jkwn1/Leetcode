class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
    int n = (int) nums.size();
    int bitCount = (1 << n);
    bool poss = false;
    int workingBit = 0;
    for (int bitmask = 1; bitmask < bitCount; bitmask++) {
        long long prod = 1;
        for (int i = 0; i < n; i++) {
            if (bitmask & (1 << i)) {
                prod *= nums[i];
                if (prod > target) {
                    break;
                }
            }
        }
        if (prod == target) {
            poss = true;
            workingBit = bitmask;
            break;
        }
    }
    if (poss) {
        long long prod = 1;
        for (int i = 0; i < n; i++) {
            if (!(workingBit & (1 << i))) {
                prod *= nums[i];
                if (prod > target) {
                    break;
                }
            }
        }
        return (prod == target);
    }
    return false;
}
};
