class Solution {
public:
    bool isValid(string s) {

        stack<char> sk;
        
        for (int i = 0; i < s.size(); i++) {

            if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{') sk.push(s.at(i));
            else if ((s.at(i) == ')' || s.at(i) == ']' || s.at(i) == '}') && !sk.empty()) {

                if (sk.top() == '(' && s.at(i) == ')') sk.pop();
                else if (sk.top() == '[' && s.at(i) == ']') sk.pop();
                else if (sk.top() == '{' && s.at(i) == '}') sk.pop();
                else return false;
            }
            else return false;
        }

        if (sk.empty()) return true;
        else return false;
    }
};
