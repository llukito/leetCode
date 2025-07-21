class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vect;
        for(int n : arr){
            int ones = getOnes(n);
            vect.push_back({ones, n});
        }
        sort(vect.begin(), vect.end());
        vector<int> res;
        for(pair<int,int> pr : vect){
            res.push_back(pr.second);
        }
        return res;
    }

    int getOnes(int n){
        int num = 0;
        while(n!=0){
            if(n%2==1){
                num++;
            }
            n/=2;
        }
        return num;
    }
};