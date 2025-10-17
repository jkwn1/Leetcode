class Solution {
public:
    string removeSubstring(string s, int k) {
        string stack;
    
        for (char c : s) {
            stack.push_back(c);
            int n = stack.size();
            if (n >= 2 * k && c == ')') {
                bool isKBalanced = true;
    
                for (int i = n - 2 * k; i < n - k; i++) {
                    if (stack[i] != '(') {
                        isKBalanced = false;
                        break;
                    }
                }
    
                if (isKBalanced) {
                    for (int i = n - k; i < n; i++) {
                        if (stack[i] != ')') {
                            isKBalanced = false;
                            break;
                        }
                    }
                }
                if (isKBalanced) {
                    stack.erase(stack.end() - 2 * k, stack.end());
                }
            }
        }
        return stack;
    }
};
