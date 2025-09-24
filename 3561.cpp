class Solution {
public:
string resultingString(string s) {
    string ret = "";
    int n = (int) s.length();
    for (int i = 0; i < n; i++) {
        int size = (int) ret.length();
        if (size != 0 && ((abs(ret[size-1]-s[i]) % 24) == 1)) {
            ret.pop_back();
        }
        else {
            ret += s[i];
        }
    }
    return ret;
}
};
