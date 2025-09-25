class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        vector<bool> ans(nums.size(), false);
        map<int, int> multi;
        for (int i: nums) {
            if (multi.contains(i)) {
                multi[i]++;
            }
            else {
                multi.insert({i, 1});
            }
        }
        ans[0] = (nums.size() >= k);
        vector<bool> poss(k+1, false);
        poss[0] = true;
        int used = 0;
        for (int cap = 2; cap <= nums.size(); cap++) {
            if (multi.contains(cap-1)) {
                used += multi[cap-1];
                for (int end = k; end >= cap-1; end--) {
                    for (int mult = 0; mult <= multi[cap-1]; mult++) {
                        if (mult * (cap-1) > end) break;
                        if (poss[end - mult * (cap-1)]) {
                            poss[end] = true;
                            break;
                        }
                    }
                }
            }
            for (int mult = 0; mult <= nums.size() - used; mult++) {
                if (mult * (cap) > k) break;
                if (poss[k - mult * cap]) {
                    ans[cap-1] = true;
                    break;
                }
            }
        }
        return ans;
    }
};
