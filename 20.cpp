class Solution {
public:
    bool isValid(string s) {
        string open = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open += "(";
            }
            else if (s[i] == '[') {
                open += "[";
            }
            else if (s[i] == '{') {
                open += "{";
            }
            else if (s[i] == ')') {
                if (open.size() == 0) return false;
                if (open[open.size()-1] != '(') {
                    return false;
                }
                else open = open.substr(0, open.size()-1);
            }
            else if (s[i] == ']') {
                if (open.size() == 0) return false;
                if (open[open.size()-1] != '[') {
                    return false;
                }
                else open = open.substr(0, open.size()-1);
            }
            else if (s[i] == '}') {
                if (open.size() == 0) return false;
                if (open[open.size()-1] != '{') {
                    return false;
                }
                else open = open.substr(0, open.size()-1);
            }
        }
        return (open.size() == 0);
    }
};
