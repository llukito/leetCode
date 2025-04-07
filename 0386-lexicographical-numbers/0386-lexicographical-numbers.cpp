class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1; i<=9; i++){
            fill(res, i, n);
        }
        return res;
    }

    void fill(vector<int>& res, long long n, int curr){
        if(n>curr){
            return;
        }
        res.push_back(n);
       for(int i=0; i<=9; i++){
            n*=10;
            n+=i;
            if(n>curr){
                break;
            }
            fill(res,n,curr);
            n-=i;
            n/=10;
       }
    }
};