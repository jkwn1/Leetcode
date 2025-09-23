class Solution {
public:
    vector<int> father;
vector<int> height;
vector<int> sizes;


int find(int node) {
    if (father[node] != node) {
        father[node] = find(father[node]);
    }
    return father[node];
}

void unite(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);
    if (height[rootA] > height[rootB]) {
        father[rootB] = rootA;
        sizes[rootA] += sizes[rootB];
        height[rootA] = max(height[rootA], height[rootB] + 1);
    } else {
        father[rootA] = rootB;
        sizes[rootB] += sizes[rootA];
        height[rootB] = max(height[rootB], height[rootA] + 1);
    }
}
    
vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    father = vector<int>(n, 0);
    sizes = vector<int>(n, 0);
    height = vector<int>(n, 0);

    for (int i = 0; i < n; i++) {
        father[i] = i;
    }

    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i-1] <= maxDiff) {
            unite(i, i-1);
        }
    }
    vector<bool> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        ans[i] = (find(queries[i][0]) == find(queries[i][1]));
    }

    return ans;
}
};
