class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = (int) nums.size();
        for (int start = 0; start < n; start++) {
            set<int> evens;
            set<int> odds;
            for (int end = start; end < n; end++) {
                int i = nums[end];
                if (i % 2 == 0) evens.insert(i);
                else odds.insert(i);
                if (evens.size() == odds.size()) {
                    ans = max(ans, end - start + 1);
                }
            }
        }
        return ans;
    }
};
