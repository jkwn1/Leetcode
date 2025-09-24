class Solution {
public:
struct element {
    int l;
    int v;

    element(int l1, int v1): l(l1), v(v1) {}

    bool operator<(const element& other) const {
        if (l != other.l) {
            return l < other.l;
        }
        return v > other.v;
    }
};

long long maxTotal(vector<int>& value, vector<int>& limit) {
    vector<element> elements;
    for (int i = 0; i < value.size(); i++) {
        elements.push_back(element(limit[i], value[i]));
    }
    sort(elements.begin(), elements.end());
    long long sum = 0;
    int size = 0;
    int index = 0;
    int taken = 0;
    vector<int> toDelete(value.size(), 0);
    while (index < value.size()) {
        bool needbreak = false;
        while (elements[index].l <= size) {
            index++;
            if (index >= value.size()) {
                needbreak = true;
                break;
            }
        }
        if (needbreak) break;

        auto element = elements[index];
        index++;
        sum += element.v;
        if (element.l < value.size()) toDelete[element.l]++;
        size++;

        while (index < value.size() && elements[index].l <= size) {
            index++;
            if (index >= value.size()) {
                break;
            }
        }
        if (size < value.size()) {
            int deleted = toDelete[size];
            toDelete[size] = 0;
            size -= deleted;
        }
    }
    return sum;
}
};
