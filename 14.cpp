class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curr = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int length = min(curr.length(), strs[i].length());
            string next = "";
            for (int j = 0; j < length; j++) {
                if (curr[j] == strs[i][j]) {
                    next += curr[j];
                }
                else break;
            }
            curr = next;
        }
        return curr;
    }
};
