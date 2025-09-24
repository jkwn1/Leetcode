class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int) matrix.size();
        int k1 = n/2;
        int k2 = (n+1)/2;

        for (int i = 0; i < k1; i++) {
            for (int j = 0; j < k2; j++) {
                int one = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                int two = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = one;
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = two;
            }
        }
    }
};
