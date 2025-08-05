class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0; int right = 0;
        set<int> st; int res = 0; unordered_map<int,int> mp;
        while(right<fruits.size()){
            st.insert(fruits[right]);
            mp[fruits[right]]++;
            if(st.size()>2){
                res = max(res, right-left);
                for(int i=left; i<right; i++){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0){
                        st.erase(fruits[i]);
                        left = i+1;
                        break;
                    }
                }
                right++;
                cout<<res<<" "<<left<<" "<<right<<endl;
            } else {
                right++;
            }
        }
        res = max(res, right-left);
        return res;
    }
};