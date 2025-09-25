class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> ret = {1, 1};
        vector<int> newRet;
        for (int i = 2; i <= rowIndex; i++) {
            newRet = vector<int>(i+1, 1);
            for (int j = 0; j < i - 1; j++) {
                newRet[j+1] = ret[j]+ret[j+1];
            }
            ret = newRet;
        }
        return ret;
    }
};
