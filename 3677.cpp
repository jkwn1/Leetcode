class Solution {
public:
    int countBinaryPalindromes(long long n) {
        if (n == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return 2;
        if (n == 3) return 3;
        vector<int> counts(60, 0);
        counts[1] = 2;
        counts[2] = 3;
        int curr = 2;
        for (int i = 3; i < 52; i++) {
            counts[i] = counts[i-1] + curr;
            if (i % 2 == 0) curr*=2;
        }
        int e2 = (int) log2(n);
        long long p2 = pow(2, e2);
        int count = counts[e2];
        long long rem = n - p2-1;
        if (rem < 0) return count;
        rem /= 2;
        e2-=2;
        p2 /= 4;
        while (rem > 0) {
            if (p2 == 0) {
                if (rem > 0) count++;
                return count;
            }
            if (p2 == 1) return (count + (int) min(2LL, rem+1));
    
            if (rem > p2) {
                count += pow(2, e2/2);
                rem -= (p2+1);
            }
            rem /= 2;
            e2-=2;
            p2 /= 4;
        }
        if (rem >= 0) count++;
        return count;
    }
};
