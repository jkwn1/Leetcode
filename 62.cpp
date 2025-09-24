class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<long long> fac(201);
        vector<long long> inv(201);
        long long curr = 1;
        fac[0] = 1;
        for (int i = 1; i < 201; i++) {
            curr = (curr * i) % 2147483647;
            fac[i] = curr;
        }
        long long res = 1;
        long long x = fac[200];
        long long k = 2147483645;
        while (k > 0) {
            if (k % 2 == 1) { res = res * x % 2147483647; }
            x = x * x % 2147483647;
            k /= 2;
        }
        inv[200] = res;
	    for (int i = 200; i >= 1; i--) { 
            inv[i - 1] = inv[i] * i % 2147483647;
        }
        inv[0] = 1;

        return (((fac[m+n-2] * inv[m-1] % 2147483647) * inv[n-1]) % 2147483647 + 2147483647) % 2147483647;
    }
};
