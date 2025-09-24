class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long long k = n;
        if (k < 0) {
            k = -k;
            x = 1/x;
        }
        double ans = 1;
        while (k > 1) {
            if (k % 2 == 1) {
                ans *= x;
            }
            k /= 2;
            x = x * x;
        }
        return ans * x;
    }
};
