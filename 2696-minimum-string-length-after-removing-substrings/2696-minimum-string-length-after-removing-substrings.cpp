class Solution {
public:
    int minLength(string s) {
        while(true){
            string curr;
            bool b = true;
            for(int i=0; i<s.length(); i++){
                if(i<s.length()-1 && ((s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'C' && s[i+1] == 'D'))){
                    b = false;
                    i++;
                } else {
                    curr+=s[i];
                }
            }
            s = curr;
            cout<<s<<endl;
            if(s.empty())return 0;
            if(b)break;
        }
        return s.length();
    }
}; 