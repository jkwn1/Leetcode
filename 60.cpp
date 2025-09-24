class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> counts(n);
        vector<string> digits;
        int count = 1;
        for (int i = 1; i <= n; i++) {
            count *= i;
            counts[n-i] = count;
            digits.push_back(to_string(i));
        }
        string ans = "";

        for (int i = 1; i < n; i++) {
            ans += digits[(k - 1) / counts[i]];
            digits.erase(digits.begin()+(k - 1) / counts[i]);
            k %= counts[i];
            if (k == 0) k = counts[i];
        }
        ans += digits[0];

        return ans;
    }
};
