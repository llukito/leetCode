class Solution {
public:
    string truncateSentence(string s, int k) {
        string curr;
        for(char ch : s){
            if(ch==' '){
                k--;
            }
            if(k==0)return curr;
            curr+=ch;
        }
        return s;
    }
};