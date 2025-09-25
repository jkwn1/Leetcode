class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> sC(26, 0);
        vector<int> tC(26, 0);
        for (int i = 0; i < s.length(); i++) {
            sC[s[i]-'a']++;
        }
        for (int j = 0; j < s.length(); j++) {
            tC[t[j]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (sC[i] != tC[i]) return false;
        }
        return true;
    }
};
