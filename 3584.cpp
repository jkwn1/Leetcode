class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
    int n = (int) nums.size();
    vector<long long> dpLargest(n, 0);
    vector<long long> dpSmallest(n, 0);
    dpLargest[0] = nums[0];
    dpSmallest[0] = nums[0];
    for (int i = 1; i < n; i++) {
        dpLargest[i] = max(dpLargest[i-1], (long long) nums[i]);
        dpSmallest[i] = min(dpSmallest[i-1], (long long) nums[i]);
    }
    long long ans = -10000000001;
    for (int i = m-1; i < n; i++) {
        ans = max(ans, dpLargest[i-m+1] * nums[i]);
        ans = max(ans, dpSmallest[i-m+1] * nums[i]);
    }
    return ans;
}
};
