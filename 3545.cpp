class Solution {
public:
    int minDeletion(string s, int k) {
    int n = s.length();
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++) {
        count[s[i]-'a']++;
    }
    sort(count.begin(), count.end());
    int sum = 0;
    for (int i = 25; i > 25-k; i--) {
        sum += count[i];
    }
    return n - sum;
}
};
