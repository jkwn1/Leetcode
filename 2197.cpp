class Solution {
public:
    vector<int> parent;
    vector<int> child;

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    int findChild(int node) {
        if (child[node] != node) {
            child[node] = findChild(child[node]);
        }
        return child[node];
    }

    void unite(int A, int B) {
        int rootA = find(A);
        int rootB = find(B);
        if (rootA == rootB) return;
        parent[rootB] = rootA;
        child[rootA] = max(child[rootA], B);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        queue<pair<int, int>> q;
        parent = vector<int>(nums.size());
        child = vector<int>(nums.size()+1);
        for (int i = 0; i < nums.size(); i++) {
            parent[i] = i;
            child[i] = i;
        }
        child[nums.size()] = nums.size();
        for (int i = 0; i < nums.size()-1; i++) {
            q.push({i, i+1});
        }
        while (!q.empty()) {
            int ind1 = q.front().first;
            int ind2 = q.front().second;
            q.pop();
            ind1 = find(ind1);
            ind2 = find(ind2);
            if (ind1 == ind2) continue;
            int overlap = gcd(nums[ind1], nums[ind2]);
            if (overlap != 1) {
                nums[ind1] = nums[ind1] / overlap * nums[ind2];
                nums[ind2] = 1;
                unite(ind1, ind2);
                if (ind1 != 0) {
                    q.push({find(ind1-1), ind1});
                }
                if (findChild(ind1) < nums.size()-1) {
                    q.push({ind1, findChild(ind1) + 1});
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (find(i) == i) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
