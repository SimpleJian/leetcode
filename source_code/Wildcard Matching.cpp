class Solution {

public:

    bool isMatch(const char *s, const char *p) {

        const char *ts, *tp=NULL;

        while(*s){

            if(*p=='?' || *p==*s)   s++, p++;

            else if(*p=='*'){

                ts = s;

                tp = p++;

            }

            else if(tp){

                s = ++ts;

                p = tp+1;

            }

            else    return 0;

        }

        while(*p=='*')  p++;

        return !(*p);

    }

};
