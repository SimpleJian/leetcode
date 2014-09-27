class Solution {

public:

    bool match(char left, char right){

        return '('==left && ')'==right || '['==left && ']'==right || '{'==left && '}'==right;

    }

    bool isValid(string s) {

        stack<char> char_stack;

        for(int i=0; i<s.length(); i++){

            if(char_stack.empty())  char_stack.push(s[i]);

            else{

                char t = char_stack.top();

                if(match(t, s[i]))  char_stack.pop();

                else    char_stack.push(s[i]);

            }

        }

        return char_stack.empty();

    }

};
