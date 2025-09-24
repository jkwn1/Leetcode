class Solution {
public:
    string convertToBase7(int num) {
        int ans = 0;
        int div = 5764801;
        while (div > 0) {
            int digit = num / div;
            num -= digit * div;
            ans *= 10;
            ans += digit;
            div /= 7;
        }
        return to_string(ans);
    }
};
