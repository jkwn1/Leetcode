class Solution {
public:
    char processStr(string s, long long k) {
    int n = (int) s.length();
    long long finalLength = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            finalLength++;
        }
        else if (s[i] == '*') {
            if (finalLength >= 1) {
                finalLength--;
            }
        }
        else if (s[i] == '#') {
            finalLength*=2;
        }
    }
    if (k > finalLength-1) return '.';

    long long currLength = finalLength;
    long long currIndex = k;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            currLength--;
            if (currLength == currIndex) return s[i];
        }
        else if (s[i] == '*') {
            currLength++;
        }
        else if (s[i] == '#') {
            if (currIndex >= (currLength/2)) {
                currIndex -= (currLength/2);
            }
            currLength/=2;
        }
        else { // reverse
            currIndex = (currLength-1) - currIndex;
        }
        
    }
    return '.';
}
};
