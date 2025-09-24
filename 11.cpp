class Solution {
public:
    int maxArea(vector<int>& height) {
    int n = (int) height.size();
    vector<pair<int, int>> heights(n);
    for (int i = 0; i < n; i++) {
        heights[i] = {height[i], i};
    }
    sort(heights.begin(), heights.end(), greater<pair<int, int>>());
    int first = heights[0].second;
    int second = heights[0].second;
    int maxHeight = heights[0].first;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        maxHeight = min(maxHeight, heights[i].first);
        first = min(first, heights[i].second);
        second = max(second, heights[i].second);
        ans = max(ans, (second - first) * maxHeight);
    }
    return ans;
}
};
