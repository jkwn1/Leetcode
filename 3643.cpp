class Solution {
public:
vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    for (int i = x; 2 * i < 2 * x + k; i++) {
        for (int j = y; j < y+k; j++) {
            int temp = grid[i][j];
            grid[i][j] = grid[x + (x+k-1-i)][j];
            grid[x + (x+k-1-i)][j] = temp;
        }
    }
    return grid;
}
};
