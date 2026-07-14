class Solution {
public:
    int passwordStrength(string password) {
        int res = 0;
        unordered_set<int> st;
        for(char ch : password){
            if(!st.count(ch)){
                if(ch >= 'a' && ch <= 'z')res++;
                else if(ch >= 'A' && ch <= 'Z')res+=2;
                else if(ch >= '0' && ch <= '9')res+=3;
                else res+=5;
                st.insert(ch);
            }
        }
        return res;
    }
};
