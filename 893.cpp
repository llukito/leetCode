class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> st;
        for(string s : words){
            string odds, evens = "";
            for(int i = 0; i < s.size(); i++){
                if(i%2==0){
                    evens+=s[i];
                } else {
                    odds+=s[i];
                }
            }
            sort(evens.begin(), evens.end());
            sort(odds.begin(), odds.end());
            st.insert(evens+"|"+odds);
        }
        return st.size();
    }
};
