class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
    int pos = 0;
    int neg = 0;
    int n = (int) nums.size();
    for (int i: nums) {
        if (i == 1) pos++;
        else neg++;
    }

    int prev = -1;
    int total = 0;
    if (pos % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (prev == -1) {
                    prev = i;
                }
                else {
                    total += i - prev;
                    prev = -1;
                }
            }
        }
        if (total <= k) return true;
    }


    prev = -1;
    total = 0;
    if (neg % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (nums[i] == -1) {
                if (prev == -1) {
                    prev = i;
                }
                else {
                    total += i - prev;
                    prev = -1;
                }
            }
        }
        if (total <= k) return true;
    }

    return false;
}
};
