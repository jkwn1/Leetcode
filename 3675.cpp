class Solution {
public:
    int minOperations(string s) {
        vector<int> vec(26, 0); // counts of a, b, ...
        for (int i = 0; i < s.length(); i++) {
            vec[s[i]-'a']++;
        }
        for (int i = 1; i < 26; i++) {
            if (vec[i] != 0) {
                return 26-i;
            }
        }
        return 0;
    }
};
