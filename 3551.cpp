class Solution {
public:
    vector<int> parent;
vector<int> height;
vector<int> sizes;


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
        sizes[rootA] += sizes[rootB];
        height[rootA] = max(height[rootA], height[rootB] + 1);
    } else {
        parent[rootA] = rootB;
        sizes[rootB] += sizes[rootA];
        height[rootB] = max(height[rootB], height[rootA] + 1);
    }
}

int minSwaps(vector<int>& nums) {

    parent = vector<int>(nums.size() + 1);
    height = vector<int>(nums.size() + 1, 0);
    sizes = vector<int>(nums.size() + 1, 1);

    for (int i = 1; i < nums.size()+1; ++i) {
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> sorted(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        int sum = 0;
        while (x > 0) {
            sum += (x % 10);
            x /= 10;
        }
        sorted[i] = {sum, {nums[i], i}};
    }
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < nums.size(); i++) {
        unite(i, sorted[i].second.second);
    }

    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (find(i) == i) {
            ret += sizes[i] - 1;
        }
    }
    return ret;
}
};
