class Solution {
public:
    bool halvesAreAlike(string s) {
        if(s.length()%2==1)return false;
        int first = 0;
        int second = 0;
        for(int i=0; i<s.length()/2; i++){
            char ch = s[i];
            ch = tolower(ch);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                first++;
            }
        }

        for(int i=s.length()/2; i<s.length(); i++){
            char ch = s[i];
            ch = tolower(ch);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                second++;
            }
        }
        return first == second;
    }
};