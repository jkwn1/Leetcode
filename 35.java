class Solution {
    public int searchInsert(int[] nums, int target) {
        int lo = 0;
        int hi = nums.length;
		while (lo < hi) {
			int mid = (hi + lo) / 2;
			if (target <= nums[mid]) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		return lo;
    }
}
