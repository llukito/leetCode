class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0; int y = 0;
        map<char,int> mp1;
        map<char, int> mp2;
        for(char ch : secret){
            mp1[ch]++;
        }
        for(char ch : guess){
            mp2[ch]++;
        }
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                x++;
                mp1[secret[i]]--;
                mp2[secret[i]]--;
            }
        }
        for(auto& entry : mp1){
            if(entry.second!=0 && mp2.count(entry.first)){
                y+= min(entry.second, mp2[entry.first]);
            }
        }
        string res  = to_string(x);
        res+="A";
        res+=to_string(y);
        res+="B";
        return res;
    }
};