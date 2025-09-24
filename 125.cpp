class Solution {
public:
    bool isPalindrome(string s) {
        string reducedS = "";
        int n = (int) s.length();
        for (int i = 0; i < n; i++) {
            if (s[i]-'a' >= 0 && s[i]-'a' < 26) {
            reducedS += s[i];
            }
            if (s[i]-'A' >= 0 && s[i]-'A' < 26) {
                reducedS += tolower(s[i]);
            }
            if (s[i] - '0' >= 0 && s[i] - '0' < 10) {
                reducedS += s[i];
            }
        }
        int n2 = (int) reducedS.length();
        for (int i = 0; i * 2 < n2; i++) {
            if (reducedS[i] != reducedS[n2-1-i]) {
                return false;
            }
        }
        return true;
    }
};
