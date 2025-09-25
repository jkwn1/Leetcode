class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<vector<string>> ans(queries.size(), vector<string>(4, ""));
        map<string, vector<string>> used;
        for (int q = 0; q < queries.size(); q++) {
            string curr = queries[q];
            if (used.contains(curr)) {
                ans[q] = used[curr];
                continue;
            }
            for (int w = 0; w < wordlist.size(); w++) {
                int currLevel = 3;
                string comp = wordlist[w];
                if (curr.length() != comp.length()) continue;
                bool match = true;
                for (int i = 0; i < curr.length(); i++) {
                    if (curr[i] != comp[i]) {
                        currLevel = min(currLevel, 2);
                        if (tolower(curr[i]) == comp[i] || curr[i] == tolower(comp[i])) {
                            continue;
                        }
                        currLevel = min(currLevel, 1);
                        if (isVowel(curr[i]) && isVowel(comp[i])) {
                            continue;
                        }
                        match = false;
                        break;
                    }
                }
                if (match && ans[q][currLevel] == "") {
                    ans[q][currLevel] = comp;
                }
            }
            used.insert({curr, ans[q]});
        }
        vector<string> ret(queries.size(), "");
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < 4; j++) {
                if (ans[i][j] != "") {
                    ret[i] = ans[i][j];
                }
            }
        }
        return ret;
    }
};
