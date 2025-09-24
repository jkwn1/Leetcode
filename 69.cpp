class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = 46340;
        int mid;
        while (lo < hi) {
            mid = (lo + hi + 1) / 2;
            if (mid * mid <= x) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
