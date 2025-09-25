class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ret(2, 0);
        int mult = 1;
        int dig = 0;
        while (n > 0) {
            dig = n % 10;
            n /= 10;
            if (dig >= 2) {
                ret[0] += mult;
                ret[1] += mult * (dig - 1);
            }
            else {
                ret[0] += mult * (5 + dig);
                ret[1] += mult * (5);
                n-=1;
            }
            mult *= 10;
        }
        if (n < 0) {
            ret[0] -= mult/10 * 5;
            ret[1] -= mult/10 * 5;
        }
        return ret;
    }
};
