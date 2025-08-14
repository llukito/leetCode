class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int,int> m;
        for(int n : costs){
            m[n]++;
        }
        int res = 0;
        for(auto& entry : m){
            long long cost = entry.first; long long num = entry.second;
            res+= min(coins/cost, num);
            coins-=cost*num;
            if(coins <= 0)break;
        }
        return res;
    }
};