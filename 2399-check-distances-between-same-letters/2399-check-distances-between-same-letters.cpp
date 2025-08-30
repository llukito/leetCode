class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> vect(26, 0);
        vector<bool> se(26,false);
        vector<int> used(s.length(), false);
        for(int i=0; i<s.length(); i++){
            if(!used[i]){
                for(int j=i+1; j<s.length(); j++){
                    if(s[j] == s[i]){
                        vect[s[i]-'a'] = j-i-1;
                        se[s[i]-'a'] = true;
                        used[i] = true;
                        used[j] = true;
                        break;
                    }
                }
            }
        }
        for(int i=0; i<vect.size(); i++){
            if(se[i]){
                if(vect[i]!=distance[i])return false;
            }
        }
        return true;
    }
};