class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string str : details){
            int age = stoi(str.substr(11,2));
            res+= age > 60 ? 1 : 0;
        }
        return res;
    }
};