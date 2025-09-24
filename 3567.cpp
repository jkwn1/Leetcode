class Solution {
public:
vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int m = (int) grid.size();
    int n = (int) grid[0].size();
    vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));
    if (k == 1) return ans;
    for (int i = 0; i <= m-k; i++) {
        map<int, int> currMap;
        for (int x = i; x < i + k; x++) {
            for (int y = 0; y < k; y++) {
                if (!currMap.contains(grid[x][y])) {
                    currMap.insert({grid[x][y], 1});
                }
                else {
                    currMap.at(grid[x][y])++;
                }
            }
        }
        int minVal = 2000001;
        int prev = -10000000;
        for (auto it: currMap) {
            if (prev != -10000000) {
                minVal = min(minVal, abs(it.first - prev));
            }
            prev = it.first;
        }
        if (minVal == 2000001) {
            minVal = 0;
        }
        ans[i][0] = minVal;
        for (int j = 1; j <= n-k; j++) {
            for (int x = i; x < i + k; x++) {
                currMap[grid[x][j-1]]--;
                if (currMap[grid[x][j-1]] == 0) {
                    currMap.erase(grid[x][j-1]);
                }

                if (!currMap.contains(grid[x][j+k-1])) {
                    currMap.insert({grid[x][j+k-1], 1});
                }
                else {
                    currMap.at(grid[x][j+k-1])++;
                }
            }
            minVal = 2000001;
            prev = -10000000;
            for (auto it: currMap) {
                if (prev != -10000000) {
                    minVal = min(minVal, abs(it.first - prev));
                }
                prev = it.first;
            }
            if (minVal == 2000001) {
                minVal = 0;
            }
            ans[i][j] = minVal;
        }
    }
    return ans;
}
};
