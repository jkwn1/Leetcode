class Solution {
public:
    int countPermutations(vector<int>& complexity) {
    int n = (int) complexity.size();
    int complexity0 = complexity[0];
    for (int i = 1; i < n; i++) {
        if (complexity[i] <= complexity[0]) {
            return 0;
        }
    }
    long long ans = 1;
    for (int i = 2; i < n; i++) {
        ans = (ans * i) % 1000000007;
    }
    return ans;
}
};
