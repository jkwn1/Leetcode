class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        bool poss = true;
        int length = (int) log10(x)+1;
        int p10 = (int) pow(10, length - 1);
        int mult = 1;
        for (int i = 0; i < length / 2; i++) { // digit at 10^i and 10^(length - i - 1)
            int digit1 = (x / mult) % 10;
            int digit2 = (x / (p10 / mult)) % 10;
            if (digit1 != digit2) {poss = false; break;}
            mult *= 10;
        }
        return poss;
    }
};
