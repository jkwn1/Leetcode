class Solution {
public:
    int pivotInteger(int n) {
        int lo = 1;
        int hi = n;
        int sum = n * (n+1) / 2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid * (mid-1) == sum - mid) {
                return mid;
            }
            if (lo == hi) return -1;
            if (mid * (mid-1) < sum - mid) {
                lo = mid+1;
            }
            else {
                hi = mid;
            }
        }
        return -1;
    }
};
