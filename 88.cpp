class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind1 = 0;
        int ind2 = 0;
        vector<int> newNums(m+n);
        while (ind1 + ind2 < m+n) {
            if (ind1 == m) {
                newNums[ind1+ind2] = nums2[ind2];
                ind2++;
                continue;
            }
            if (ind2 == n) {
                newNums[ind1+ind2] = nums1[ind1];
                ind1++;
                continue;
            }
            if (nums1[ind1] < nums2[ind2]) {
                newNums[ind1+ind2] = nums1[ind1];
                ind1++;
            }
            else {
                newNums[ind1+ind2] = nums2[ind2];
                ind2++;
            }
        }
        nums1 = newNums;
    }
};
