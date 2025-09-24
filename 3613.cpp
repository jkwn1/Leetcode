class Solution {
public:
    vector<int> parent;
vector<int> height;
int componentCount;

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
    componentCount--;
    if (height[rootA] > height[rootB]) {
        parent[rootB] = rootA;
        height[rootA] = max(height[rootA], height[rootB] + 1);
    } else {
        parent[rootA] = rootB;
        height[rootB] = max(height[rootB], height[rootA] + 1);
    }
}
int minCost(int n, vector<vector<int>>& edges, int k) {
    sort(edges.begin(), edges.end(),[](const vector<int>& a, const vector<int>& b) {return a[2] < b[2];});

    parent = vector<int>(n);
    height = vector<int>(n);
    componentCount = n;

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        height[i] = 0;
    }
    int ans = 0;
    if (componentCount <= k) return ans;
    for (int i = 0; i < edges.size(); ++i) {
        unite(edges[i][0], edges[i][1]);
        if (componentCount == k) {
            return edges[i][2];
        }
    }
    return ans;
}
};
