class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string,int> mp;
        return check(price, special, needs, mp);
    }

    int check(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string,int>& mp){
        pair<int,string> pr = see(needs);
        int ch = pr.first;
        string str = pr.second;
        if(mp.contains(str)){
            return mp[str];
        }
        if(ch == 0){
            return 0;
        }
        int count = 0;
        for(int i=0; i<price.size(); i++){
            count+=price[i]*needs[i];
        }
        for(int i=0; i<special.size(); i++){
            vector<int> vect = special[i];
            bool worth = true;
            for(int i=0; i<vect.size()-1; i++){
                if(needs[i]-vect[i]<0){
                    worth = false;
                    break;
                }
            }
            if(worth){
                for(int i=0; i<vect.size()-1; i++){
                    needs[i]-=vect[i];
                }
                count = min(count, vect.back() + check(price, special, needs, mp));
                for(int i=0; i<vect.size()-1; i++){
                    needs[i]+=vect[i];
                }
            }
        }
        return mp[str] = count;
    }

    pair<int,string> see(vector<int>& needs){
        string str;
        bool zeros = true;
        for(int n : needs){
            str+=to_string(n);
            if(n!=0){
                zeros = false;
            }
        }
        return zeros ? make_pair(0,str) : make_pair(1,str);
    }
};