class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        string res = "";
        char ch = '-';
        for(auto& entry : mp){
            if(entry.second%2==1){
                ch = entry.first;
            }
            for(int i=0; i<entry.second/2; i++){
                res+=entry.first;
            }
        }
        string temp = res;
        if(ch != '-')res+=ch;
        reverse(temp.begin(), temp.end());
        res+=temp;
        return res;
    }
};