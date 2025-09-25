class Solution {
public:
bool partitionArray(vector<int>& nums, int k) {
    if (nums.size() % k != 0) return false;
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) == mp.end()) {
            mp[nums[i]] = 1;
        }
        else {
            mp[nums[i]]++;
        }
    }
    
    for (auto const &it: mp) {
        if (nums.size() / k < it.second) return false;
    }
    return true;
}
};
