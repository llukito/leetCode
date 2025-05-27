class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]] = i;
        }
        stack<int> st;
        unordered_set<char> used;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(!used.count(ch)){
                used.insert(ch);
                if(st.empty()){
                    st.push(ch);
                } else {
                    while(!st.empty() && st.top()>ch && mp[st.top()]>i){
                        used.erase(st.top());
                        st.pop();
                    }
                    st.push(ch);
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};