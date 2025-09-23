class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
    int sideLength = (1 << N);
    vector<vector<int>> grid(sideLength, vector<int>(sideLength, 0));

    int xPos = 0;
    int yPos = sideLength - 1;
    for (int i = 0; i < sideLength * sideLength; i++) {
        grid[xPos][yPos] = i;
        if (i == sideLength * sideLength - 1) break;
        int mod = i % 4;
        if (mod == 0) {
            xPos++;
        }
        else if (mod == 1) {
            yPos--;
        }
        else if (mod == 2) {
            xPos--;
        }
        else {
            int div = 16;
            while (true) {
                if ((i+1) % div == 0) {
                    div *= 4;
                }
                else {
                    int j = (i+1) % div;
                    div /= 4;
                    if (j / div == 1) {
                        int change = (int) sqrt(div);
                        xPos += change;
                        yPos += change - 1;
                    }
                    else if (j / div == 2) {
                        yPos--;
                    }
                    else {
                        int change = (int) sqrt(div);
                        xPos -= change;
                        yPos += change - 1;
                    }
                    break;
                }
            }
        }
    }
    return grid;
}
};
