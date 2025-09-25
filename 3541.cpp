class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> counts(26, 0);
        for (int i = 0; i < s.length(); i++) {
            counts[s[i]-'a']++;
        }
        int vMax = 0;
        int cMax = 0;
        for (int i = 0; i < 26; i++) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
                vMax = max(vMax, counts[i]);
            }
            else {
                cMax = max(cMax, counts[i]);
            }
        }
        return vMax+cMax;
    }
};
