class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> cardss;
        for(int n : cards){
            cardss.push_back((double)n);
        }
        return possible(cardss);
    }

    bool possible(vector<double>& vect){
        bool b = false;
        check(vect, b);
        return b;
    }

    void check(vector<double>& vect, bool& b){
        if(b)return;
        if(vect.size()==1){
            if(fabs(vect[0] - 24.0) < 1e-6){
                b = true;
            }
            return;
        }
        for(int j =0; j<vect.size(); j++){
            for(int k = 0; k<vect.size(); k++){
                if(j==k)continue;
                double d1 = vect[j]; double d2 = vect[k];
                vector<double> newVect;
                for(int i=0; i<vect.size(); i++){
                    if(i==j || i==k)continue;
                    newVect.push_back(vect[i]);
                }
                double res = 0;
                res = d1+d2;
                newVect.push_back(res);
                check(newVect, b);
                if(b)return;
                res = d1-d2;
                newVect[newVect.size()-1] = res;
                check(newVect, b);
                if(b)return;
                res = d1*d2;
                newVect[newVect.size()-1] = res;
                check(newVect, b);
                if(b)return;
                res = static_cast<double>(d1)/d2;
                newVect[newVect.size()-1] = res;
                check(newVect, b);
            }
        }
    }
    
    void fill(vector<vector<double>>& perms, vector<double>& cards, int index){
        if(index == cards.size()){
            perms.push_back(cards);
        }
        for(int i=index; i<cards.size(); i++){
            swap(cards[index], cards[i]);
            fill(perms, cards, index+1);
            swap(cards[index], cards[i]);
        }
    }
};