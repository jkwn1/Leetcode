class Solution {
public:
    long long MOD = 1e9+7;
    vector<vector<long long>> matrixMult(vector<vector<long long>> a, vector<vector<long long>> b, int n) {
    vector<vector<long long>> ret(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
    vector<vector<long long>> exp(vector<vector<long long>> x, long long n, long long size) {
        vector<vector<long long>> res = vector<vector<long long>>(size, vector<long long>(size, 0)); // identity
        for (int i = 0; i < size; i++) {
            res[i][i] = 1;
        }
        while (n > 0) {
            if (n % 2 == 1) res = matrixMult(res, x, size);
            x = matrixMult(x, x, size);
            n /= 2;
        }
        return res;
    }
    int zigZagArrays(int n, int l, int r) {
        int size = r - l;
        vector<vector<long long>> start = vector<vector<long long>>(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size-i; j++) {
                start[i][j] = 1;
            }
        }
        vector<vector<long long>> last = exp(start, n, size);
        long long ans = 0;
        for (int i = 0; i < size; i++) {
            ans = (ans + last[i][0]) % MOD;
        }
        int ret = (2 * ans) % MOD;
        if (ret < 0) ret += MOD;
        return ret;
    }
};
