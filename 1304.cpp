class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret(n, 0);
        for (int i = 0; i < n/2; i++) {
            ret[i] = -n + i;
            ret[n-1-i] = n - i;
        }
        return ret;
    }
};
