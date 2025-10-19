class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = (int) s.length();
        if (n == 1) {
            if (s[0] > target[0]) {
                return s;
            }
            else {
                return "";
            }
        }
        vector<int> countS(26, 0);
        vector<int> countT(26, 0);
        for (int i = 0; i < n; i++) {
            countS[s[i]-'a']++;
        }
        int end = n;
        for (int i = 0; i < n; i++) {
            int curr = target[i]-'a';
            countT[curr]++;
            if (countT[curr] > countS[curr]) {
                countT[curr]--;
                end = i;
                break;
            }
        }
        if (end == n) {
            countT[target[n-1]-'a']--;
            end = n-1;
        }
    
        string ans = "";
        bool breakAll = false;
        while (end >= 0) {
            for (char i = target[end]; i <= 'z'; i++) {
                if (i == target[end]) continue;
                if (countS[i-'a']-countT[i-'a'] > 0) {
                    countT[i-'a']++;
                    ans = target.substr(0, end) + i;
                    breakAll = true;
                    break;
                }
            }
            if (breakAll) break;
            if (end == 0) break;
            countT[target[end-1]-'a']--;
            end--;
        }
        if (ans == "") return "";
    
        for (char i = 'a'; i <= 'z'; i++) {
            if (countS[i-'a']-countT[i-'a'] > 0) {
                string addition(countS[i-'a']-countT[i-'a'], i);
                ans += addition;
            }
        }
        return ans;
    }
};
