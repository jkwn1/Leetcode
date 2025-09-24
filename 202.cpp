class Solution {
public:
    bool isHappy(int n) {
        vector<bool> hasHappened(800, false);
        int curr = 0;
        while (n > 0) {
            curr += (n % 10) * (n % 10);
            n /= 10;
        }
        hasHappened[curr] = true;
        while (curr != 1) {
            int next = 0;
            while (curr > 0) {
                next += (curr % 10) * (curr % 10);
                curr /= 10;
            }
            if (hasHappened[next]) {
                return false;
            }
            hasHappened[next] = true;
            curr = next;
        }
        return true;
    }
};
