class Solution {
public:
    string countAndSay(int n) {
        string encoding = "1";
        for (int i = 2; i <= n; i++) {
            int len = (int) encoding.length();
            int prev = encoding[0] - '0';
            int count = 1;
            string newEncoding = "";
            for (int j = 1; j < len; j++) {
                if (prev != encoding[j]-'0') {
                    newEncoding += to_string(count) + to_string(prev);
                    prev = encoding[j]-'0';
                    count = 1;
                }
                else {
                    count++;
                }
            }
            newEncoding += to_string(count) + to_string(prev);
            encoding = newEncoding;
        }
        return encoding;
    }
};
