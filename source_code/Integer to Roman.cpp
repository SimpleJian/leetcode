class Solution {

public:

    string get_str(int d, int n_z){

        string c1 = "IXCM";

        string c5 = "VLD";

        string ret = "";

        if(d<=3){

            for(int i=0; i<d; i++)  ret += c1[n_z];

        }

        else if(d==4){

            ret += c1[n_z];

            ret += c5[n_z];

        }

        else if(d<=8){

            ret += c5[n_z];

            for(int i=0; i<d-5; i++)   ret += c1[n_z];

        }

        else{

            ret += c1[n_z];

            ret += c1[n_z+1];

        }

        return ret;

    }

    string intToRoman(int num) {

        return get_str(num/1000, 3)+get_str(num/100%10, 2)+get_str(num/10%10, 1)+get_str(num%10, 0);

    }

};
