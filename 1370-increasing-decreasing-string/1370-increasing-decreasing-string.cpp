class Solution {
public:
    string sortString(string s) {
        sort(s.begin(), s.end());
        string curr;

        while(true){
            auto it = min_element(s.begin(), s.end());
            curr+=*it;
            s.erase(it);
            if(s.empty())break;
            while(true){
                char ch = curr.back();
                auto itt = upper_bound(s.begin(),s.end(),ch);
                if(itt == s.end()){
                    break;
                }
                curr+=*itt;
                s.erase(itt);
            }
            if(s.empty())break;
            auto itt = max_element(s.begin(), s.end());
            curr+=*itt;
            s.erase(itt);
             if(s.empty())break;
            while(true){
                int idx = get(s, curr.back());
                if(idx == -1)break;
                curr+=s[idx];
                s.erase(s.begin()+idx);
            }
             if(s.empty())break;
        }

        return curr;
    }

    int get(string& s, char ch){
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]<ch)return i;
        }
        return -1;
    }
};