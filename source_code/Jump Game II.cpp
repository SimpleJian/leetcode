class Solution {

public:

    int jump(int A[], int n) {

        if(n<2) return 0;

        int cur=0, next=0, step=0;

        for(int i=0; i<n; i++){

            if(i>cur){

                step++;

                if(next>=n-1)   return step;

                cur = next;

            }

            next = max(next, i+A[i]);

        }

    }

};
