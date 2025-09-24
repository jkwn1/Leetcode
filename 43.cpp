class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = (int) num1.length();
        int len2 = (int) num2.length();
        vector<int> digits(len1+len2+1, 0);
        for (int i = 0; i < len1; i++) {
            int dig1 = num1[len1-i-1]-'0';
            for (int j = 0; j < len2; j++) {
                int dig2 = num2[len2-j-1]-'0';
                int prod = dig1 * dig2;
                digits[i+j] += prod;
            }
        }
        string ans = "";
        for (int i = 0; i < len1+len2; i++) {
            digits[i+1] += (digits[i] / 10);
            ans = to_string(digits[i] % 10) + ans;
        }
        int countLeadingZeroes = 0;
        while (ans[countLeadingZeroes] == '0') {
            countLeadingZeroes++;
        }
        if (countLeadingZeroes == len1+len2) return to_string(0);
        return ans.substr(countLeadingZeroes, len1+len2-countLeadingZeroes);
    }
};
