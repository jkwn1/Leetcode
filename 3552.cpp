class Solution {
public:
    int minMoves(vector<string>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<pair<int, int>>> portals(26, vector<pair<int, int>>());
    vector<bool> portalUsed(26, false);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int charVal = matrix[i][j] - 'A';
            if (charVal >= 0 && charVal < 26) {
                portals[charVal].push_back({i, j});
            }
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {0, 0}});
    vector<vector<int>> dist(m, vector<int>(n, 1000000));
    dist[0][0] = 0;

    while (!q.empty()) {
        int d = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if (dist[x][y] != d) continue;

        int charVal = matrix[x][y] - 'A';
        if (charVal >= 0 && charVal < 26) {
            if (!portalUsed[charVal]) {
                portalUsed[charVal] = true;
                for (pair<int, int> p: portals[charVal]) {
                    int x2 = p.first;
                    int y2 = p.second;
                    if (dist[x2][y2] > d) {
                        dist[x2][y2] = d;
                        q.push({d, {x2, y2}});
                    }
                }
            }
        }

        if (x > 0 && matrix[x-1][y] != '#') {
            if (dist[x-1][y] > d+1) {
                dist[x-1][y] = d + 1;
                q.push({d + 1, {x-1, y}});
            }
        }
        if (y > 0 && matrix[x][y-1] != '#') {
            if (dist[x][y-1] > d + 1) {
                dist[x][y-1] = d + 1;
                q.push({d + 1, {x, y-1}});
            }
        }
        if (x < m-1 && matrix[x+1][y] != '#') {
            if (dist[x+1][y] > d + 1) {
                dist[x+1][y] = d + 1;
                q.push({d + 1, {x+1, y}});
            }
        }
        if (y < n-1 && matrix[x][y+1] != '#') {
            if (dist[x][y+1] > d + 1) {
                dist[x][y+1] = d + 1;
                q.push({d + 1, {x, y+1}});
            }
        }
    }
    if (dist[m-1][n-1] == 1000000) {
        return -1;
    }
    return dist[m-1][n-1];
}
};
