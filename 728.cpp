class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for (int i = left; i <= right; i++) {
            int n = i;
            bool poss = true;
            while (n > 1) {
                int dig = n % 10;
                n /= 10;
                if (dig == 0 || i % dig != 0) {
                    poss = false;
                    break;
                }
            }
            if (poss) ret.push_back(i);
        }
        return ret;
    }
};
