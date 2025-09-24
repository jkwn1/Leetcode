class Solution {
public:
    string generateTag(string caption) {
        string ret = "#";
        int n = (int) caption.length();
        bool prevSpace = true;
        bool firstWord = true;
        for (int i = 0; i < n; i++) {
            if (caption[i] != ' ') {
                char c = tolower(caption[i]);
                if (prevSpace && !firstWord) {
                    ret += toupper(c);
                }
                else {
                    ret += c;
                }
                firstWord = false;
                prevSpace = false;
            }
            else {
                prevSpace = true;
            }
        }
        if (ret.length() > 100) {
            return ret.substr(0, 100);
        }
        return ret;
    }
};
