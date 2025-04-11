class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        set<string> result;
        transf(result, s, 0);
        vector<string> final(result.begin(),result.end());
        return final;
    }

    void transf(set<string>& result, string main, int index){
        if(index==main.size()){
            result.insert(main);
            return;
        }
        char original = main[index];
        main[index]=tolower(main[index]);
        transf(result, main, index+1);
        main[index]=toupper(main[index]);
        transf(result, main, index+1);
        main[index]=original;
    }
};