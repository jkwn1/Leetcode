class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int k: nums) {
            if (s.contains(k)) {
                return true;
            }
            s.insert(k);
        }
        return false;
    }
};
