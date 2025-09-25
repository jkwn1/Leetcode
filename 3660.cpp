class Solution {
public:
vector<int> parent;
vector<int> height;
vector<int> largest;

int find(int node) {
    if (parent[node] != node) {
        parent[node] = find(parent[node]);
    }
    return parent[node];
}

void unite(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);
    if (rootA == rootB) return;
    if (height[rootA] > height[rootB]) {
        parent[rootB] = rootA;
        largest[rootA] = max(largest[rootA], largest[rootB]);
        height[rootA] = max(height[rootA], height[rootB] + 1);
    } else {
        parent[rootA] = rootB;
        largest[rootB] = max(largest[rootB], largest[rootA]);
        height[rootB] = max(height[rootB], height[rootA] + 1);
    }
}
vector<int> maxValue(vector<int>& nums) {
    parent = vector<int>(nums.size());
    height = vector<int>(nums.size(), 0);
    largest = vector<int>(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        parent[i] = i;
        largest[i] = nums[i];
    }
    int currLargest = -1;
    int currLargestIndex = -1;
    vector<int> largestBefore(nums.size(), -1);
    for (int i = 0; i < nums.size(); i++) {
        if (currLargest < nums[i]) {
            currLargest = nums[i];
            currLargestIndex = i;
        }
        else if (currLargest > nums[i]){
            unite(currLargestIndex, i);
        }
        largestBefore[i] = currLargest;
    }
    int currSmallest = 2000000000;
    int currSmallestIndex = -1;
    for (int i = (int) nums.size()-1; i >= 0; i--) {
        if (currSmallest > nums[i]) {
            if (currSmallestIndex != -1 && largestBefore[i] > nums[currSmallestIndex]) {
                unite(currSmallestIndex, i);
            }
            currSmallest = nums[i];
            currSmallestIndex = i;
        }
        else if (currSmallest < nums[i]) {
            unite(currSmallestIndex, i);
        }
    }
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        result.push_back(largest[find(i)]);
    }
    return result;
}
};
