class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int mostRecent6Pow = -1;
        int pow10 = 0;
        while (n > 0) {
            if (n % 10 == 6) {
                mostRecent6Pow = pow10;
            }
            pow10++;
            n /= 10;
        }
        if (mostRecent6Pow != -1) {
            num += 3 * pow(10, mostRecent6Pow);
        }
        return num;
    }
};
