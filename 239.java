class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        TreeMap<Integer, Integer> multiset = new TreeMap<Integer, Integer>();
        int n = nums.length;
        int[] answerArray = new int[n-k+1];
        for (int i = 0; i < k; i++) {
            if (multiset.containsKey(nums[i])) {
                multiset.put(nums[i], multiset.get(nums[i]) + 1);
            } else {
                multiset.put(nums[i], 1);
            }
        }
        for (int i = 0; i < n-k; i++) {
            answerArray[i] = multiset.lastKey();
            multiset.put(nums[i], multiset.get(nums[i]) - 1);
            if (multiset.get(nums[i]) == 0) { multiset.remove(nums[i]); }
            if (multiset.containsKey(nums[i+k])) {
                multiset.put(nums[i+k], multiset.get(nums[i+k]) + 1);
            } else {
                multiset.put(nums[i+k], 1);
            }
        }
        answerArray[n-k] = multiset.lastKey();
        return answerArray;
    }
}
