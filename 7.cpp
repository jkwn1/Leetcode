class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648) return 0;
        int mult = 1;
        if (x < 0) {
            x = -x;
            mult = -1;
        }
        long long y = 0;
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            y *= 10;
            y += digit;
        }

        if (y > INT_MAX) {
            return 0;
        }
        return mult * y;
    }
};
