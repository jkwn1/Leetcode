class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ret;
        for (int i = 0; i < order.size(); i++) {
            for (int j = 0; j < friends.size(); j++) {
                if (order[i] == friends[j]) {
                    ret.push_back(friends[j]);
                    break;
                }
            }
        }
        return ret;
    }
};
