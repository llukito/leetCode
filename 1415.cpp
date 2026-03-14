class Solution {
public:
    string getHappyString(int n, int k) {
        int all = 3*(1<<(n-1));
        if(k > all)return "";
        string res;
        fill(n, k, "", res);
        return res;
    }

    void fill(int n, int& k, string str, auto& res){
        if(str.size() == n){
            k--;
            if(k == 0){
                res = str;
            }
            return;
        }
        if(str.empty()){
            fill(n, k, "a", res);
            fill(n, k, "b", res);
            fill(n, k, "c", res);
        } else {
            for(char ch = 'a'; ch <= 'c'; ch++){
                if(str.back() != ch){
                    fill(n, k, str+ch, res);
                }
            }
        }
    }
};
