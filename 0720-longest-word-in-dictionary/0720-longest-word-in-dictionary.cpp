class Solution {
public:
    string longestWord(vector<string>& words) {
        int length = INT_MIN;
        string res = "";
        unordered_set<string> s(words.begin(), words.end());
        for(string str : words){
            bool b = true;
            for(int i=1; i<str.length(); i++){
                if(!s.count(str.substr(0, i))){
                    b = false;
                    break;
                }
            }
            if(b){
                int n = str.length();
                if(length < n){
                   cout<<"j"<<endl;
                    res = str;
                    length = str.length();
                    cout<<"1"<<endl;
                } else if(length == n && (res.empty() || res > str)){
                    res = str;
                    length = str.length();
                }
            }
        }
        return res;
    }
};