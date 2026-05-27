class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> vect(26,0);
        for(char ch : word){
            if(isLower(ch)){
                if(vect[ch-'a'] == -1)continue;
                if(vect[ch-'a'] == 2){
                    vect[ch-'a'] = -1;
                    continue;
                }
                vect[ch-'a'] = 1;
            } else {
                if(vect[ch-'A'] == -1)continue;
                if(vect[ch-'A'] == 0){
                    vect[ch-'A'] = -1;
                    continue;
                }
                vect[ch-'A'] = 2;
            }
        }
        int cnt = 0;
        for(int n : vect){
            if(n == 2)cnt++;
        }
        return cnt;
    }

    bool isLower(char& ch){
        return ch >= 'a' && ch <='z';
    }
};
