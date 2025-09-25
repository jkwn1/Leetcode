class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        vector<vector<int>> prefSum(52, vector<int>(52, 0));
        for (int i = 0; i < points.size(); i++) {
            prefSum[points[i][0]+1][points[i][1]+1] = 1;
        }
        for (int i = 1; i < 52; i++) {
            for (int j = 1; j < 52; j++) {
                prefSum[i][j] += prefSum[i-1][j] + prefSum[i][j-1]-prefSum[i-1][j-1];
            }
        }
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0]+1;
            int y1 = points[i][1]+1;
            for (int j = i+1; j < points.size(); j++) {
                int x2 = points[j][0]+1;
                int y2 = points[j][1]+1;
                if (x1 >= x2 && y1 <= y2) {
                    if (prefSum[x1][y2]-prefSum[x1][y1-1]-prefSum[x2-1][y2]+prefSum[x2-1][y1-1] == 2) {
                        count++;
                    }
                }
                else if (x1 <= x2 && y1 >= y2) {
                    if (prefSum[x2][y1]-prefSum[x2][y2-1]-prefSum[x1-1][y1]+prefSum[x1-1][y2-1] == 2) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
