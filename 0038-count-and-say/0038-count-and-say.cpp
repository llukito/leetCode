class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i=1; i<n; i++){
            cout<<s;
            string temp="";
            int freq = 0;
            for(int j=0; j<s.length(); j+=freq){
                int frequency = 0;
                for(int k = j; k<s.length(); k++){
                    if(s[j]==s[k]){
                        frequency++;
                    }else{
                        break;
                    }
                }
                temp+=to_string(frequency);
                temp+=s[j];
                freq = frequency;
            }
            s = temp;
        }
        return s;
    }
};