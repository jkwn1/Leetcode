class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n > k) {
            long long ret = n-k;
            return ret * k;
        }
        else if (m > k) {
            long long ret = m-k;
            return ret * k;
        }
        else {
            return 0;
        }
    }
};
