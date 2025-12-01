class Solution {
public: 
    #define ll long long
    const ll MAX = 1e14;
    const ll MIN = 0;

    ll maxRunTime(int n, vector<int>& batteries) {
        ll right = MAX;
        ll left = MIN; 
        ll res = 0;
        while(left <= right){
            ll mid = left + (right-left)/2;
            if(possible(n, batteries, mid)){
                left = mid + 1;
                res = mid;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }

    bool possible(int& n, auto& batteries, ll mid){
        ll allCapacity = 0;
        for(ll m : batteries){
            allCapacity+=min(m, mid);
        }
        return allCapacity >= mid*n;
    }
};