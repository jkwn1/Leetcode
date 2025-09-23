class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int start = -1;
        int end = -1;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] != ' ') {
                if (end == -1) {
                    end = i;
                }
            }
            else {
                if (end != -1) {
                    start = i;
                    break;
                }
            }
        }
        return end - start;
    }
};
