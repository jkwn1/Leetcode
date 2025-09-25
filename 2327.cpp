class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> counts(n+1, 0);
        for (int i = 1; i < 1 + forget; i++) {
            counts[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j < min(n+1, i+forget); j++) {
                counts[j] = (counts[j] + counts[i]) % 1000000007L;
            }
        }
        return (int) counts[n];
    }
};
