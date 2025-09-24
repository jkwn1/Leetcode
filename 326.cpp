class Solution {
public:
    bool isPowerOfThree(int n) {
        vector<int> powersOfThree;
        int curr = 1;
        powersOfThree.push_back(1);
        for (int i = 1; i <= 19; i++) {
            curr *= 3;
            powersOfThree.push_back(curr);
        }
        return binary_search (powersOfThree.begin(), powersOfThree.end(), n);
    }
};
