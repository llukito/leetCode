class Solution {
public:
    int minFlips(int a, int b, int c) {
       string sa = get(a);
       string sb = get(b);
       string sc = get(c);
       int res = 0;
        for(int i=0; i<32; i++){
            int an = sa[i]-'0';
            int bn = sb[i]-'0';
            int cn = sc[i]-'0';
            int n = an|bn;
            if(n !=cn){
                if(cn == 1){
                    res++;
                } else {
                    if(an==1)res++;
                    if(bn==1)res++;
                }
            }
        }
        return res;
    }

    string get(int n){
        bitset<32> s(n);
        return s.to_string();
    }
};
