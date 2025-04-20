class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string cur;
        check(cur, n, res);
        return res;
    }

    void check(string& curr, int n, vector<string>& res){
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        if(curr.empty() || curr[curr.length()-1]=='1'){
            curr+='0';
            check(curr, n, res);
            curr.pop_back();
            curr+='1';
            check(curr, n, res);
            curr.pop_back();
        } else {
            curr+='1';
            check(curr, n, res);
            curr.pop_back();
        }
    }
};