class Solution {
public:
    string freqAlphabets(string s) {
        string prev;
        for(int i=s.length()-1; i>=0; i--){
            char ch = s[i];
            if(ch == '#'){
                string curr = to_string(s[i-2]);
                curr+=s[i-1]; i-=2;
                int n = stoi(curr);
                char ch = (char)('a'+n-1);
                ch = tolower(ch);
                prev+=ch;
            } else {
                prev+=(char)('a'+s[i]-1-'0');
            }
            cout<<prev<<endl;
        }
        reverse(prev.begin(), prev.end());
        return prev;
    }
};