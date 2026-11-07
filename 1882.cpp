class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        multiset<pair<int, int>> st;
        for(int i = 0; i < servers.size(); i++){
            st.insert({servers[i], i});
        }

        map<long long, vector<int>> mp;
        vector<int> ans(tasks.size());
        long long t = 0;
        for(int j = 0; j < tasks.size(); j++){
            t = max(t, (long long)j);
            if(st.empty()){
                t = max(t, mp.begin()->first);
            }
            while(!mp.empty() && mp.begin()->first <= t){
                for(int idx : mp.begin()->second){
                    st.insert({servers[idx], idx});
                }
                mp.erase(mp.begin());
            }
            int idx = st.begin()->second;
            st.erase(st.begin());
            ans[j] = idx;
            mp[t + tasks[j]].push_back(idx);
        }
        return ans;
    }
};
