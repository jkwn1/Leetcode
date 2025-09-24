class Solution {
public:
    string intToRoman(int num) {
        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> twos = {"", "X", "XX", "XXX", "XL", "L", "LX",  "LXX", "LXXX", "XC"};
        vector<string> threes = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> fours = {"", "M", "MM", "MMM"};
        string ans = "";
        ans = ones[num % 10] + ans;
        num /= 10;
        ans = twos[num % 10] + ans;
        num /= 10;
        ans = threes[num % 10] + ans;
        num /= 10;
        ans = fours[num % 10] + ans;
        return ans;
    }
};
