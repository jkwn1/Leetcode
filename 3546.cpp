class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<long long> colSums(m, 0);
    for (int i = 0; i < m; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += grid[i][j];
        }
        colSums[i] = sum;
    }

    vector<long long> rowSums(n, 0);
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j < m; j++) {
            sum += grid[j][i];
        }
        rowSums[i] = sum;
    }

    long long totalSum = 0;
    for (int i = 0; i < m; i++) {
        totalSum += colSums[i];
    }

    if (totalSum % 2 != 0) return false;

    long long currSum = 0;
    for (int i = 0; i < m; i++) {
        currSum += colSums[i];
        if (currSum == totalSum / 2) {
            return true;
        }
        if (currSum > totalSum / 2) {
            break;
        }
    }
    currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += rowSums[i];
        if (currSum == totalSum / 2) {
            return true;
        }
        if (currSum > totalSum / 2) {
            break;
        }
    }
    return false;
}
};
