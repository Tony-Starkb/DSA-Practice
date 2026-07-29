class Solution {
public:
    bool isValid(string s) {
        stack<char> parantheses;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parantheses.push(s[i]);
            }else {
                if(parantheses.size() == 0) {
                    return false;
                }else if(
                    s[i] == ')' && parantheses.top() == '(' ||
                    s[i] == ']' && parantheses.top() == '[' ||
                    s[i] == '}' && parantheses.top() == '{'
                ) {
                    parantheses.pop();
                }else {
                    return false;
                }
            }
        }

        return parantheses.size() == 0;
    }
};