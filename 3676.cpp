class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int count = 0;
        int n = (int) nums.size();
        set<int> used;
        map<int, vector<int>, std::greater<>> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp.insert({nums[i], {i}});
            }
            else {
                mp[nums[i]].push_back(i);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> v = it->second;
            for (int k: v) {
                used.insert(k);
            }
            for (int k: v) {
                int leftClosest = -1;
                auto leftIt = used.lower_bound(k);
                if (leftIt != used.begin()) {
                    --leftIt;
                    leftClosest = *leftIt;
                }
                if (leftClosest != -1 && k - leftClosest >= 2) {
                    count++;
                }
    
                int rightClosest = n;
                auto rightIt = used.upper_bound(k);
                if (rightIt != used.end()) {
                    rightClosest = *rightIt;
                }
                if (rightClosest != n && rightClosest - k >= 2) {
                    count++;
                }
            }
        }
        return count;
    }
};
