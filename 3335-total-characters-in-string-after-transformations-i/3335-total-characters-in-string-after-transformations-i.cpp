class Solution {
public:
    const int mod =1e9 +7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> vect(26, 0);
        for(char ch : s){
            vect[ch-'a']++;
        }
        for(int i=0; i<t; i++){
            vector<long long> nv(26, 0);
            for(int i=0; i<25; i++){
                nv[i+1] = vect[i];
            }
            nv[0]+=vect[25];
            nv[1]+=vect[25];
            vect = nv;
        }
        int sum = 0;
        for(int n : vect){
            sum+=n;
        }
        return sum;
    }
};