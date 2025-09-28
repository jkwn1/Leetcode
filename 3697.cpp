class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ret;
        long long mult = 1;
        while (n > 0) {
            if (n % 10 != 0) {
                ret.push_back((n % 10) * mult);
            }
            n /= 10;
            mult *= 10;
        }
        sort(ret.rbegin(), ret.rend());
        return ret;
    }
};
