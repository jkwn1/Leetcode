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

    long long currSum = 0;
    vector<bool> exists(100001, false); // so far, do these values exist?
    exists[0] = true;
    for (int i = 0; i < m-1; i++) {
        currSum += colSums[i];
        for (int j = 0; j < n; j++) {
            exists[grid[i][j]] = true;
        }
        if (2 * currSum - totalSum >= 0 && 2 * currSum - totalSum <= 100000) {
            if (exists[2 * currSum - totalSum]) {
                if (2 * currSum - totalSum == 0) return true;
                if (n == 1) {
                    if (grid[i][0] == 2 * currSum - totalSum || grid[0][0] == 2 * currSum - totalSum) {
                        return true;
                    }
                    continue;
                }
                if (i != 0) return true;
                if ((2 * currSum - totalSum == grid[i][0])
                    || (2 * currSum - totalSum == grid[i][n - 1])) return true;
            }
        }
    }
    exists = vector<bool>(100001, false); // so far, do these values exist?
    exists[0] = true;
    currSum = 0;
    for (int i = m-1; i >= 1; i--) {
        currSum += colSums[i];
        for (int j = 0; j < n; j++) {
            exists[grid[i][j]] = true;
        }
        if (2 * currSum - totalSum >= 0 && 2 * currSum - totalSum <= 100000) {
            if (exists[2 * currSum - totalSum]) {
                if (2 * currSum - totalSum == 0) return true;
                if (n == 1) {
                    if (grid[i][0] == 2 * currSum - totalSum || grid[m-1][0] == 2 * currSum - totalSum) {
                        return true;
                    }
                    continue;
                }
                if (i != m-1) return true;
                if (2 * currSum - totalSum == grid[i][0]
                    || 2 * currSum - totalSum == grid[i][n - 1]) return true;
            }
        }
    }

    exists = vector<bool>(100001, false); // so far, do these values exist?
    exists[0] = true;

    currSum = 0;
    for (int j = 0; j < n-1; j++) {
        currSum += rowSums[j];
        for (int i = 0; i < m; i++) {
            exists[grid[i][j]] = true;
        }
        if (2 * currSum - totalSum >= 0 && 2 * currSum - totalSum <= 100000) {
            if (exists[2 * currSum - totalSum]) {
                if (2 * currSum - totalSum == 0) return true;
                if (m == 1) {
                    if (grid[0][j] == 2 * currSum - totalSum || grid[0][0] == 2 * currSum - totalSum) {
                        return true;
                    }
                    continue;
                }
                if (j != 0) return true;
                if (2 * currSum - totalSum == grid[0][j]
                    || 2 * currSum - totalSum == grid[m-1][j]) return true;
            }
        }

    }

    exists = vector<bool>(100001, false); // so far, do these values exist?
    exists[0] = true;

    currSum = 0;
    for (int j = n-1; j >= 1; j--) {
        currSum += rowSums[j];
        for (int i = 0; i < m; i++) {
            exists[grid[i][j]] = true;
        }
        if (2 * currSum - totalSum >= 0 && 2 * currSum - totalSum <= 100000) {
            if (exists[2 * currSum - totalSum]) {
                if (2 * currSum - totalSum == 0) return true;
                if (m == 1) {
                    if (grid[0][j] == 2 * currSum - totalSum || grid[0][n-1] == 2 * currSum - totalSum) {
                        return true;
                    }
                    continue;
                }
                if (j != n-1) return true;
                if (2 * currSum - totalSum == grid[0][j]
                    || 2 * currSum - totalSum == grid[m-1][j]) return true;
            }
        }
    }

    return false;
}

};
