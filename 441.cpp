class Solution {
public:
    int arrangeCoins(int n) {
        long long nL = n;
        long long k = (long long) sqrt(nL * 2);
        if (k * (k+1) / 2 <= nL) return k;
        else return k-1;
    }
};
