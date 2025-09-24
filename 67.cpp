class Solution {
public:
    string addBinary(string a, string b) {
        int aDigits = a.length();
        int bDigits = b.length();
        string ans = "";
        int rem = 0;

        if (bDigits > aDigits) {
            for (int i = 0; i < aDigits; i++) {
                int nextDigit = (a[aDigits-1-i] - '0') + (b[bDigits-1-i] - '0') + rem;
                if (nextDigit >= 2) {
                    rem = 1;
                }
                else {
                    rem = 0;
                }
                nextDigit %= 2;
                ans = to_string(nextDigit) + ans;
            }
            for (int i = aDigits; i < bDigits; i++) {
                int nextDigit = (b[bDigits-1-i]-'0') + rem;
                if (nextDigit >= 2) {
                    rem = 1;
                }
                else {
                    rem = 0;
                }
                nextDigit %= 2;
                ans = to_string(nextDigit) + ans;
            }
        }
        else {
            for (int i = 0; i < bDigits; i++) {
                int nextDigit = (a[aDigits-1-i] - '0') + (b[bDigits-1-i] - '0') + rem;
                if (nextDigit >= 2) {
                    rem = 1;
                }
                else {
                    rem = 0;
                }
                nextDigit %= 2;
                ans = to_string(nextDigit) + ans;
            }
            for (int i = bDigits; i < aDigits; i++) {
                int nextDigit = (a[aDigits-1-i]-'0') + rem;
                if (nextDigit >= 2) {
                    rem = 1;
                }
                else {
                    rem = 0;
                }
                nextDigit %= 2;
                ans = to_string(nextDigit) + ans;
            }
        }
        if (rem == 1) {
            ans = "1" + ans;
        }
        return ans;
    }
};
