class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int) nums.size();
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (int j = i+1; j <= min(n-1, i + nums[i]); j++) {
                if (!visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        return visited[n-1];
    }
};
