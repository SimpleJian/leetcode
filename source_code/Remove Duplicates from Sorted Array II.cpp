class Solution {

public:

    int removeDuplicates(int A[], int n) {

        if(n<=2)    return n;

        int last = A[0], cnt = 1, k=0;

        A[k++] = last;

        for(int i=1; i<n; i++){

            if(A[i]==last){

                if(cnt<2){

                    cnt++;

                    A[k++] = last;

                }

            }

            else{

                last = A[i];

                cnt = 1;

                A[k++] = last;

            }

        }

        return k;

    }

};
