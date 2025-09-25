class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        bool currPoss=true;
        for (int i = 0; i<text.length(); i++) {
            if (text[i] == ' ') {
                if (currPoss) count++;
                else currPoss = true;
            }
            bool poss = true;
            for (int j = 0; j < brokenLetters.length(); j++) {
                if (text[i] == brokenLetters[j]) {
                    poss = false;
                }
            }
            if (!poss) currPoss = false;
        }
        if (currPoss) count++;
        return count;
    }
};
