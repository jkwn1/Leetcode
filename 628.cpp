class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int minimum1 = 2000;
        int minimum2 = 2000;
        int maximum1 = -2000;
        int maximum2 = -2000;
        int maximum3 = -2000;

        for (int k: nums) {
            if (k < minimum1) {
                minimum2 = minimum1;
                minimum1 = k;
            }
            else if (k < minimum2) {
                minimum2 = k;
            }

            if (k > maximum1) {
                maximum3 = maximum2;
                maximum2 = maximum1;
                maximum1 = k;
            }
            else if (k > maximum2) {
                maximum3 = maximum2;
                maximum2 = k;
            }
            else if (k > maximum3) {
                maximum3 = k;
            }
        }
        return max(minimum1 * minimum2 * maximum1, maximum1 * maximum2 * maximum3);
    }
};
