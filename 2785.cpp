class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string sortVowels(string s) {
        vector<int> indices;
        vector<char> indicesSorted;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                indices.push_back(i);
                indicesSorted.push_back(s[i]);
            }
        }
        sort(indicesSorted.begin(), indicesSorted.end());
        for (int i = 0; i < indices.size(); i++) {
            s[indices[i]] = indicesSorted[i];
        }
        return s;
    }
};
