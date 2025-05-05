class Solution {
public:
    const long mod = 1e9 + 7;
    
    int numTilings(int n) {
        return all(0,n,false);
    }

    int all(int i, int n, bool b){
        if(i == n){
            return !b;
        }
        if(i>n)return 0;
        if(b){
            return (all(i+1, n, false)%mod + all(i+2, n, true)%mod)%mod;
        } else {
            return (all(i+1, n, false)%mod +
                    all(i+2, n, false)%mod +
                    2*all(i+2, n, true)&mod)%mod;
        }
    }
};