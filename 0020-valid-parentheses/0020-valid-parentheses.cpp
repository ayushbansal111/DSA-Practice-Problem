class Solution {
public:
    bool isValid(string s) {
        stack<char> dummy;
        for (int i = 0; i < s.length(); i++) {

            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                dummy.push(ch);
            } else {
                if (!dummy.empty()) {
                    char top = dummy.top();
                    if ((ch == '}' && top == '{') ||
                        (ch == ')' && top == '(') ||
                        (ch == ']' && top == '[')) {
                        dummy.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (dummy.empty()) {
            return true;
        } else {
            return false;
        }
    }
};