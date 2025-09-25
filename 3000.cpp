class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int currArea = 0;
        int currDiag = 0;
        for (vector<int> v: dimensions) {
            if (v[0] * v[0] + v[1] * v[1] > currDiag) {
                currDiag = v[0] * v[0] + v[1] * v[1];
                currArea = v[0] * v[1];
            }
            else if (v[0] * v[0] + v[1] * v[1] == currDiag) {
                currArea = max(currArea, v[0] * v[1]);
            }
        }
        return currArea;
    }
};
