class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int prev = 0;
        int val = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                val++;
                prev = 1;
            }
            else if (s[i] == 'V') {
                if (prev == 1) val += 3;
                else val += 5;
                prev = 5;
            }
            else if (s[i] == 'X') {
                if (prev == 1) val += 8;
                else val += 10;
                prev = 10;
            }
            else if (s[i] == 'L') {
                if (prev == 10) val += 30;
                else val += 50;
                prev = 50;
            }
            else if (s[i] == 'C') {
                if (prev == 10) val += 80;
                else val += 100;
                prev = 100;
            }
            else if (s[i] == 'D') {
                if (prev == 100) val += 300;
                else val += 500;
                prev = 500;
            }
            else if (s[i] == 'M') {
                if (prev == 100) val += 800;
                else val += 1000;
                prev = 1000;
            }
        }
        return val;
    }
};
