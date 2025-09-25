class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = 300;
        for (int i = 0; i < tasks.size(); i++) {
            ans = min(ans, tasks[i][0] + tasks[i][1]);
        }
        return ans;
    }
};
