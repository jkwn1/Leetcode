class Solution {
public:
int lengthOfLongestSubstring(string s) {
    deque<char> myQ;
    int size = s.length();
    int ans = 0;
    for (int i = 0; i < size; i++) {
        deque<char>::iterator itr = find(myQ.begin(), myQ.end(), s[i]);
        if (itr != myQ.end()) {
            ans = max((int) myQ.size(), ans);
            while (myQ.front() != s[i]) {
                myQ.pop_front();
            }
            myQ.pop_front();
        }
        myQ.emplace_back(s[i]);
    }
    ans = max((int) myQ.size(), ans);
    return ans;
}
};
