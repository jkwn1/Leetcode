class Solution {
public:
    vector<int> minDifference(int n, int k) {
    int ans = 100000;
    vector<int> res;
    if (k == 5) {
        for (int a = 1; a*a*a*a*a <= n; a++) {
            if (n % a != 0) {
                continue;
            }
            for (int b = a; b*b*b*b <= n; b++) {
                if ((n/a) % b != 0) {
                    continue;
                }
                for (int c = b; c*c*c <= n; c++) {
                    if ((n/a/b) % c != 0) {
                        continue;
                    }
                    for (int d = c; d*d <= n; d++) {
                        if ((n/a/b/c) % d != 0) {
                            continue;
                        }
                        if (n/a/b/c/d < d) continue;
                        if (ans > n/a/b/c/d - a) {
                            ans = n/a/b/c/d - a;
                            res = {a,b,c,d,n/a/b/c/d};
                        }
                    }
                }
            }
        }
    }
    else if (k == 4) {
        for (int a = 1; a*a*a*a <= n; a++) {
            if (n % a != 0) {
                continue;
            }
            for (int b = a; b*b*b <= n; b++) {
                if ((n/a) % b != 0) {
                    continue;
                }
                for (int c = b; c*c <= n; c++) {
                    if ((n/a/b) % c != 0) {
                        continue;
                    }
                    if (n/a/b/c < c) continue;
                    if (ans > n/a/b/c - a) {
                        ans = n/a/b/c - a;
                        res = {a,b,c,n/a/b/c};
                    }
                }
            }
        }
    }
    else if (k == 3) {
        for (int a = 1; a*a*a <= n; a++) {
            if ((n) % a != 0) {
                continue;
            }
            for (int b = a; b*b <= n; b++) {
                if ((n/a) % b != 0) {
                    continue;
                }
                if (n/a/b < b) continue;
                if (ans > n/a/b - a) {
                    ans = n/a/b - a;
                    res = {a,b,n/a/b};
                }
            }
        }
    }
    else if (k == 2) {
        for (int a = 1; a*a <= n; a++) {
            if ((n) % a != 0) {
                continue;
            }
            if (n/a < a) continue;
            if (ans > n/a - a) {
                ans = n/a - a;
                res = {a,n/a};
            }
        }
    }
    return res;
}
};
