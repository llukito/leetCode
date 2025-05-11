class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int result = INT_MAX;
        check(price, special, needs, result, 0);
        return result;
    }

    void check(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int& result, int curr){
        if(curr>result){
            return;
        }
        int ch = see(needs);
        if(ch == -1){
            return;
        }
        if(ch == 0){
            result = min(result, curr);
            return;
        }
        for(int i=0; i<price.size(); i++){
            if(needs[i]>0){
                needs[i]--;
                check(price, special, needs, result, curr+price[i]);
                needs[i]++;
            }
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
                check(price, special, needs, result, curr+vect.back());
                for(int i=0; i<vect.size()-1; i++){
                    needs[i]+=vect[i];
                }
            }
        }
    }

    int see(vector<int>& needs){
        bool zeros = true;
        for(int n : needs){
            if(n<0){
                return -1;
            } else if(n!=0){
                zeros = false;
            }
        }
        return zeros ? 0 : 1;
    }
};