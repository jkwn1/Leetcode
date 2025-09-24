class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> counts(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    counts[board[i][j] - '1']++;
                }
            }
            for (int j = 0; j < 9; j++) {
                if (counts[j] > 1) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<int> counts(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    counts[board[j][i] - '1']++;
                }
            }
            for (int j = 0; j < 9; j++) {
                if (counts[j] > 1) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<int> counts(9, 0);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[3*i+k][3*j+l] != '.') {
                            counts[board[3*i+k][3*j+l]-'1']++;
                        }
                    }
                }
                for (int k = 0; k < 9; k++) {
                    if (counts[k] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
