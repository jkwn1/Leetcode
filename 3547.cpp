class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
    vector<int> eCount(n, 0);
    vector<vector<int>> adj(n, vector<int>());
    for (vector<int> edge: edges) {
        eCount[edge[0]]++;
        eCount[edge[1]]++;
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (eCount[i] == 0) {
            visited[i] = true;
        }
        if (eCount[i] == 1) {
            q.push(i);
        }
    }
    vector<int> rows;
    while (!q.empty()) {
        int start = q.front();
        q.pop();
        if (visited[start]) continue;

        int count = 0;
        queue<int> q2;
        q2.push(start);
        while (!q2.empty()) {
            int cur = q2.front();
            q2.pop();
            visited[cur] = true;
            count++;
            for (int v: adj[cur]) {
                if (!visited[v]) {
                    q2.push(v);
                }
            }
        }
        rows.push_back(count);
    }

    sort(rows.begin(), rows.end(), greater<>());

    vector<int> circles;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            queue<int> q2;
            q2.push(i);
            visited[i] = true;
            while (!q2.empty()) {
                int cur = q2.front();
                q2.pop();
                count++;
                for (int v: adj[cur]) {
                    if (!visited[v]) {
                        q2.push(v);
                        visited[v] = true;
                    }
                }
            }
            circles.push_back(count);
        }
    }

    sort(circles.begin(), circles.end(), greater<>());

    long long result = 0;
    long long currNum = n+1;
    for (int i = 0; i < circles.size(); i++) {
        int count = circles[i] - 1;
        currNum--;
        long long end1 = currNum;
        long long end2 = currNum;
        while (true) {
            currNum--;
            result += end1 * currNum;
            end1 = currNum;
            count--;

            if (count == 0) {
                result += end1 * end2;
                break;
            }

            currNum--;
            result += end2 * currNum;
            end2 = currNum;
            count--;

            if (count == 0) {
                result += end1 * end2;
                break;
            }

        }
    }
    for (int i = 0; i < rows.size(); i++) {
        int count = rows[i] - 1;
        currNum--;
        long long end1 = currNum;
        long long end2 = currNum;
        while (true) {
            currNum--;
            result += end1 * currNum;
            end1 = currNum;
            count--;

            if (count == 0) {
                break;
            }

            currNum--;
            result += end2 * currNum;
            end2 = currNum;
            count--;

            if (count == 0) {
                break;
            }

        }
    }
    return result;
}
};
