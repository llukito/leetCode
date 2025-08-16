class Solution {
public:
    int beautySum(string s) {
        vector<vector<int>> prefix((int)s.length(), vector<int>(26, 0));
        for(int i=0; i<s.length(); i++){
            if(i > 0) prefix[i] = prefix[i-1];
            prefix[i][s[i]-'a']++;
        }
        int all = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                vector<int> vect = prefix[j];
                int min_ = INT_MAX; int max_ = INT_MIN;
                if(i-1>=0){
                    for(int k=0; k<26; k++){
                        vect[k]-=prefix[i-1][k];
                        if(vect[k]!=0){
                            min_ = min(min_, vect[k]);
                            max_ = max(max_, vect[k]);
                        }
                    }
                } else {
                    for(int k=0; k<26; k++){
                        if(vect[k]!=0){
                            min_ = min(min_, vect[k]);
                            max_ = max(max_, vect[k]);
                        }
                    }
                }
                if(max_ != INT_MIN && min_ != INT_MAX){
                    all+=max_ - min_;
                }
            }
        }
        return all;
    }
};