class Solution {

public:

    int get_d(char c){

        switch(c){

            case 'I':   return 1;

            case 'X':   return 10;

            case 'C':   return 100;

            case 'M':   return 1000;

            case 'V':   return 5;

            case 'L':   return 50;

            case 'D':   return 500;

        }

    }

    int romanToInt(string s) {

        int last = 0;

        int ret = 0;

        for(int i = 0; i<s.length(); i++){

            int t = get_d(s[i]);

            ret += t;

            if(t>last)  ret -= 2*last;

            last = t;

        }

        return ret;

    }

};
