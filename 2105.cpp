class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int a = 0;
        int b = (int) plants.size()-1;
        int aVal = capacityA;
        int bVal = capacityB;
        int refills = 0;
        while (a < b) {
            if (aVal < plants[a]) {
                refills++;
                aVal = capacityA;
            }
            if (bVal < plants[b]) {
                refills++;
                bVal = capacityB;
            }
            aVal -= plants[a];
            bVal -= plants[b];
            a++;
            b--;
        }
        if (a == b) {
            if (max(aVal, bVal) < plants[a]) {
                refills++;
            }
        }
        return refills;
    }
};
