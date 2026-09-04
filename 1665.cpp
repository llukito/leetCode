class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int res = tasks[0][1];
        int curr = res;
        for(auto& en : tasks){
            if(curr - en[1] < 0){
                res+=(en[1]-curr);
                curr+=(en[1]-curr);
            }
            curr = curr - en[0];
            cout<<res<<" "<<curr<<endl;
        }
        return res;
    }
};
