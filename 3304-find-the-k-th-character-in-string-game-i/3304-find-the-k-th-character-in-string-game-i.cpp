class Solution {
public:
    char kthCharacter(int k) {
        string curr = "a";
        while(curr.length()<k){
            string temp = curr;
            for(char ch : curr){
                char c = static_cast<char>((ch+1));
                if(ch=='z')c = 'a';
                temp+=c;
            }
            curr = temp;
        }
        return curr[k-1];
    }
};