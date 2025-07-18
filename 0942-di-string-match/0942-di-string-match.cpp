class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res;
        int m = 0;
        int edge = s.length();
        if(s[0] == 'I'){
            res.push_back(m++);
        } else {
            res.push_back(edge--);
        }
        for(int i=0; i<s.length(); i++){
            int curr = res.back();
            if(s[i] == 'I'){
                if(i+1<s.length() && s[i+1] == 'D'){
                    res.push_back(edge--);
                } else{
                    res.push_back(m++);
                }
            } else {
                if(i+1<s.length() && s[i+1] == 'D'){
                    res.push_back(edge--);
                } else{
                    res.push_back(m++);
                }
            }
        }
        return res;

    }
};