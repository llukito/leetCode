class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = 0;
        if(ruleKey=="type"){
            idx = 0;
        } else if(ruleKey == "color"){
            idx = 1;
        } else {
            idx = 2;
        }
        int total = 0;
        for(vector<string> vect : items){
            if(vect[idx]==ruleValue)total++;
        }
        return total;
    }
};