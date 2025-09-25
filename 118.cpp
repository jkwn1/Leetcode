class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows, vector<int>());
        ret[0] = {1};
        for (int i = 1; i < numRows; i++) {
            ret[i].push_back(1);
            for (int j = 0; j < i-1; j++) {
                ret[i].push_back(ret[i-1][j] + ret[i-1][j+1]);
            }
            ret[i].push_back(1);
        }
        return ret;
    }
};
