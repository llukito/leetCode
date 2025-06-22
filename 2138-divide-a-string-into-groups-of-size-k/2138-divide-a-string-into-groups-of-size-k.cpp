class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        string temp;
        for(int i=0; i<s.length(); i+=k){
            if(i+k-1<s.length()){
                result.push_back(s.substr(i, k));
            } else {
                temp = s.substr(i);
            }
        }
        if(!temp.empty()){
            int size = temp.length();
            for(int i=0; i<k-size; i++){
                temp+='x';
            }
            result.push_back(temp);
        }
        return result;
    }
};