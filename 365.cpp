class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        vector<vector<bool>> poss(x+1, vector<bool>(y+1, false));
        poss[0][0]=true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if (a+b == target) {
                return true;
            }
            if (!poss[x][b]) {
                poss[x][b] = true;
                q.push({x, b});
            }
            if (!poss[a][y]) {
                poss[a][y] = true;
                q.push({a, y});
            }
            if (!poss[0][b]) {
                poss[0][b] = true;
                q.push({0, b});
            }
            if (!poss[a][0]) {
                poss[a][0] = true;
                q.push({a, 0});
            }
            if (a+b <= x) {
                if (!poss[a+b][0]) {
                    poss[a+b][0] = true;
                    q.push({a+b, 0});
                }
            }
            else {
                if (!poss[x][a+b-x]) {
                    poss[x][a+b-x] = true;
                    q.push({x, a+b-x});
                }
            }
            if (a+b <= y) {
                if (!poss[0][a+b]) {
                    poss[0][a+b] = true;
                    q.push({0,a+b});
                }
            }
            else {
                if (!poss[a+b-y][y]) {
                    poss[a+b-y][y] = true;
                    q.push({a+b-y, y});
                }
            }
        }
        return false;
    }
};
