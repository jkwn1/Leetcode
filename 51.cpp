class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> curr;
        curr.reserve(n);
        for (int i = 0; i < n; i++) {
            curr.push_back({i});
        }
        for (int i = 1; i < n; i++) {
            vector<vector<int>> next;
            for (int j = 0; j < n; j++) {
                for (vector<int> k: curr) {
                    bool poss = true;
                    int s = (int) k.size();
                    for (int m = 0; m < s; m++) {
                        if (k[m] == j || (k[m]+i-m) == j || (k[m]-i+m) == j) {
                            poss = false;
                            break;
                        }
                    }
                    if (poss) {
                        vector<int> add = k;
                        add.push_back(j);
                        next.push_back(add);
                    }
                }
            }
            curr = next;
        }
        for (vector<int> k: curr) {
            vector<string> add;
            add.reserve(n);
            for (int i = 0; i < n; i++) {
                string s;
                for (int j = 0; j < k[i]; j++) {
                    s += ".";
                }
                s += "Q";
                for (int j = k[i]+1; j < n; j++) {
                    s += ".";
                }
                add.push_back(s);
            }
            ans.push_back(add);
        }
        return ans;
    }
};
