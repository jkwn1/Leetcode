class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<int> langCount(501, 0);
        set<int> needLearning;
        for (int i = 0; i < friendships.size(); i++) {
            int a = friendships[i][0];
            int b = friendships[i][1];
            set<int> langs;
            for (int l: languages[a-1]) {
                langs.insert(l);
            }
            for (int l: languages[b-1]) {
                langs.insert(l);
            }
            if (langs.size() == languages[a-1].size() + languages[b-1].size()) {
                if (!needLearning.contains(a)) {
                    for (int k: languages[a-1]) {
                        langCount[k]++;
                    }
                }
                if (!needLearning.contains(b)) {
                    for (int k: languages[b-1]) {
                        langCount[k]++;
                    }
                }
                needLearning.insert(a);
                needLearning.insert(b);
            }
        }
        int maxCount = 0;
        for (int i = 1; i <= 500; i++) {
            maxCount = max(maxCount, langCount[i]);
        }
        return (int) needLearning.size() - maxCount;
    }
};
