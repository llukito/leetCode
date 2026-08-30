class Solution {
public:
    int minimumFlips(int n) {
        string rev = getBinary(n);
        string bin = rev;
        reverse(rev.begin(), rev.end());
        int m = 0;
        for(int i = 0; i < rev.size(); i++){
            if(rev[i] != bin[i])m++;
        }
        return m;
    }

    string getBinary(int n){
        string m = "";
        while(n!=0){
            if(n % 2 == 0){
                m+='0';
            } else {
                m+='1';
            }
            n/=2;
        }
        return m;
    }
};
