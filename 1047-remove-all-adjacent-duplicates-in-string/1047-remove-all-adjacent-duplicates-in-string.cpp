class Solution {
public:
    string removeDuplicates(string s) {
        string curr = "";
        for(char ch : s){
            if(!curr.empty() && curr.back() == ch){
                curr.pop_back();
            }else{
                curr+=ch;
            }
        }
        return curr;
    }
};