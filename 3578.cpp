class Solution {
public:
    struct segTreeSum {
    vector<long long> tree; int n;

    segTreeSum(int size) {
        n = size;
        tree = vector<long long>(2*size, 0);
    }

    void update(int node, long long value) {
        for (tree[node += n] += value; node > 1; node /= 2) {
            tree[node/2] = (tree[node] + tree[node^1]) % 1000000007;
        }
    }

    long long find(int node) {
        long long val = 0;
        for (node += n; node > 0; node /= 2) {
            val = (val + tree[node]) % 1000000007;
        }
        return val;
    }

    long long sum(int l, int r) {  // sum on interval [l, r)
        long long s = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) s = (s + tree[l++]) % 1000000007;
            if (r & 1) s = (s + tree[--r]) % 1000000007;
        }
        return s;
    }
};


int countPartitions(vector<int>& nums, int k) {
// keep priorityqueue, for ex here it would be 9, it empties immediately, then it adds 4 then 1, then removes 4, adds 3, adds 7
    int n = (int) nums.size();
    vector<int> rightBound(n, n-1);
    priority_queue<pair<int, int>> pq1;
    pq1.push({nums[0], 0});
    for (int i = 1; i < n; i++) {
        int curr = nums[i];
        while (!pq1.empty() && pq1.top().first > curr + k) {
            rightBound[pq1.top().second] = min(rightBound[pq1.top().second], i-1);
            pq1.pop();
        }
        pq1.push({curr, i});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    pq2.push({nums[0], 0});
    for (int i = 1; i < n; i++) {
        int curr = nums[i];
        while (!pq2.empty() && pq2.top().first + k < curr) {
            rightBound[pq2.top().second] = min(rightBound[pq2.top().second], i-1);
            pq2.pop();
        }
        pq2.push({curr, i});
    }



    vector<int> leftBound(n, 0);
    priority_queue<pair<int, int>> pq3;
    pq3.push({nums[n-1], n-1});
    for (int i = n-2; i >= 0; i--) {
        int curr = nums[i];
        while (!pq3.empty() && pq3.top().first > curr + k) {
            leftBound[pq3.top().second] = max(leftBound[pq3.top().second], i+1);
            pq3.pop();
        }
        pq3.push({curr, i});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq4;
    pq4.push({nums[n-1], n-1});
    for (int i = n-2; i >= 0; i--) {
        int curr = nums[i];
        while (!pq4.empty() && pq4.top().first + k < curr) {
            leftBound[pq4.top().second] = max(leftBound[pq4.top().second], i+1);
            pq4.pop();
        }
        pq4.push({curr, i});
    }

    int minRightBound = rightBound[n-1];
    for (int i = n-2; i >= 0; i--) {
        rightBound[i] = minRightBound = min(rightBound[i], minRightBound);
    }
    int maxLeftBound = leftBound[0];
    for (int i = 1; i < n; i++) {
        leftBound[i] = maxLeftBound = max(leftBound[i], maxLeftBound);
    }

    segTreeSum segTree = segTreeSum(n+1);
    segTree.update(0, 1);
    for (int i = 1; i <= n; i++) {
        long long newCount = segTree.sum(leftBound[i-1], i);
        if (i == n) return (int) newCount;
        segTree.update(i, newCount);
    }
    return 1;
}
};
