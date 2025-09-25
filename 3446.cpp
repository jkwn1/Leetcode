class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        for (int length = n; length >= 1; length--) {
            int startX = n - length;
            int startY = 0;
            vector<int> arr(length);
            for (int i = 0; i < length; i++) {
                arr[i] = grid[startX+i][startY+i];
            }
            sort(arr.begin(), arr.end(), greater<>());
            for (int i = 0; i < length; i++) {
                grid[startX+i][startY+i] = arr[i];
            }
        }

        for (int length = n-1; length >= 1; length--) {
            int startX = 0;
            int startY = n - length;
            vector<int> arr(length);
            for (int i = 0; i < length; i++) {
                arr[i] = grid[startX+i][startY+i];
            }
            sort(arr.begin(), arr.end());
            for (int i = 0; i < length; i++) {
                grid[startX+i][startY+i] = arr[i];
            }
        }
        return grid;
    }
};
