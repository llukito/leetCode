class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        bitset<32> b(n);
        string s = b.to_string();
        auto it = s.find_first_of('1');
        s.erase(0,it); 
        vector<int> vect;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1'){
                vect.push_back(pow(2,(s.length()-1-i)));
            }
        }
        reverse(vect.begin(), vect.end());
        vector<int> res;
        for(vector<int> v : queries){
            int num = 1;
            for(int i=v[0]; i<=v[1]; i++){
                num*=vect[i];
            }
            res.push_back(num);
        }
        return res;
    }
};