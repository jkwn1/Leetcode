class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = (int) digits.size();
        int raise = 1;
        for (int i = n-1; i >= 0; i--) {
            if (raise == 0) continue;
            digits[i]++;
            if (digits[i] == 10) {
                digits[i] = 0;
                raise = 1;
            }
            else {
                raise = 0;
            }
        }
        if (raise == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
