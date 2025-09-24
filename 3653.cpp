class Solution {
public:
int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    vector<long long> changedNums = vector<long long>(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        changedNums[i] = nums[i];
    }
    for (int i = 0; i < queries.size(); i++) {
        int l = queries[i][0], r = queries[i][1];
        int k = queries[i][2], v = queries[i][3];
        for (int j = l; j <= r; j+=k) {
            changedNums[j] = (changedNums[j]*v) % 1000000007;
        }
    }
    long long ans = changedNums[0];
    for (int i = 1; i < changedNums.size(); i++) {
        ans = ans ^ changedNums[i];
    }
    return ans;
}

};
