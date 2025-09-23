class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    int buildingCount = (int) buildings.size();

    set<long long> worksSet;

    map<int, vector<long long>> m1;
    map<int, vector<long long>> m2;
    for (int i = 0; i < buildingCount; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];
        m1[x].push_back(y);
        m2[y].push_back(x);
    }
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        int x = it->first;
        sort(m1[it->first].begin(), m1[it->first].end());
        worksSet.insert((long long) x*(n+1)+m1[it->first].at(0));
        worksSet.insert((long long) x*(n+1)+m1[it->first].at(m1[it->first].size()-1));
    }
    for (auto it = m2.begin(); it != m2.end(); ++it) {
        int y = it->first;
        sort(m2[y].begin(), m2[y].end());
        worksSet.insert((long long) y+(n+1)*m2[it->first].at(0));
        worksSet.insert((long long) y+(n+1)*m2[it->first].at(m2[it->first].size()-1));
    }
    return buildingCount - (int) worksSet.size();
}
};
