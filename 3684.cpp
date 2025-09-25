class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> s;
        for (int i: nums) {
            s.insert(i);
        }
        vector<int> ans;
        int count = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            ans.push_back(*it);
            count++;
            if (count == k) break;
        }
        return ans;
    }
};
