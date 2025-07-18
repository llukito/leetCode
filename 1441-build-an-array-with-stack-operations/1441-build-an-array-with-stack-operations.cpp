class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> res;
        int idx = 0;
        for(int i=1; i<=n; i++){
            if(st.empty()){
                st.push(i);
                res.push_back("Push"); 
                if(st.top() == target[idx]){
                    idx++;     
                } else {
                    st.pop();
                    res.push_back("Pop");
                }
                if(idx == target.size())return res;
            } else {
                st.push(i);
                res.push_back("Push");
                if(st.top() == target[idx]){
                    idx++;     
                } else {
                    st.pop();
                    res.push_back("Pop");
                }
                if(idx == target.size())return res;
            }
        }
        return res;
    }
};