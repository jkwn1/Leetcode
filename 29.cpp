class Solution {
public:
int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;

    if (dividend > 0 && divisor > 0) {
        if (divisor == 1) return dividend;
        int ans = 0;
        while (dividend > 0) {
            dividend -= divisor;
            if (ans == 2147483647) return 2147483647;
            ans++;
        }
        if (dividend == 0) return ans;
        return ans - 1;
    }
    if (dividend > 0 && divisor < 0) {
        if (divisor == -1) {
            return -dividend;
        }
        int ans = 0;
        while (dividend > 0) {
            dividend += divisor;
            if (ans == -2147483648) return -2147483648;
            ans--;
        }
        if (dividend == 0) return ans;
        return ans + 1;
    }
    if (dividend < 0 && divisor > 0) {
        if (divisor == 1) return dividend;
        int ans = 0;
        while (dividend < 0) {
            dividend += divisor;
            if (ans == -2147483648) return -2147483648;
            ans--;
        }
        if (dividend == 0) return ans;
        return ans + 1;
    }
    if (dividend < 0 && divisor < 0) {
        if (divisor == -1) {
            if (dividend == -2147483648) return 2147483647;
            return -dividend;
        }
        int ans = 0;
        while (dividend < 0) {
            dividend -= divisor;
            if (ans == 2147483647) return 2147483647;
            ans++;
        }
        if (dividend == 0) return ans;
        return ans - 1;
    }
    return 0;
}
};
