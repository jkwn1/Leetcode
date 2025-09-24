class Solution {
public:
    string processStr(string s) {
    string res = "";
    int n = (int) s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            res += s[i];
        }
        else if (s[i] == '*') {
            if (res.length() >= 1) {
                res = res.substr(0, res.length() - 1);
            }
        }
        else if (s[i] == '#') {
            res += res;
        }
        else {
            reverse(res.begin(), res.end());
        }
    }
    return res;
}
};
