class Solution {

public:

    int removeElement(int A[], int n, int elem) {

        if(0==n)    return 0;

        int i=0, j=n-1;

        while(i<j){

            if(A[i]==elem){

                if(A[j]==elem){

                    j--;

                    continue;

                }

                else{

                    swap(A[i], A[j]);

                    i++, j--;

                }

            }

            else{

                i++;

                continue;

            }

        }

        return i+1-(A[i]==elem);

    }

};
