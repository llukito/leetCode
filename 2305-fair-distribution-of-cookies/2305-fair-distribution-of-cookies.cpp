class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> vect(k, 0);
        int res = INT_MAX;
        check(vect, cookies, 0, res);
        return res;
    }

    void check(vector<int>& vect, vector<int>& cookies, int index, int& res){
        if(index == cookies.size()){
            int min_ = INT_MAX;
            int max_ = INT_MIN;
            for(int n : vect){
                min_ = min(min_, n);
                max_ = max(max_, n);
            }
            res = min(res, max_);
            return;
        }
        for(int i=0; i<vect.size(); i++){
            vect[i]+=cookies[index];
            check(vect, cookies, index+1, res);
            vect[i]-=cookies[index];
        }
    }
};