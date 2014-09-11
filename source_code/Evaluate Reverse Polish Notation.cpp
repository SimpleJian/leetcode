ass Solution {

public:

    int cal(int a, int b, int operator_type){

        switch(operator_type){

            case 0: return a+b;

            case 1: return a-b;

            case 2: return a*b;

            case 3: return a/b;

            default:    return 0;

        }

    }

    int operator_type(string t){

        if(t.length()>1)  return -1;

        if('+'==t[0])   return 0;

        if('-'==t[0])   return 1;

        if('*'==t[0])   return 2;

        if('/'==t[0])   return 3;

        return -1;

    }

    int evalRPN(vector<string> &tokens) {

        stack<int> s;

        for(int i=0; i<tokens.size(); i++){

            string t = tokens[i];

            int op = operator_type(t);

            if(op<0)  s.push(stoi(t));

            else{

                int b = s.top();

                s.pop();

                int a = s.top();

                s.pop();

                s.push(cal(a, b, op));

            }

        }

        return s.top();

    }

};
