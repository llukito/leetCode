class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time = 0;
        int last = 0;
        for(int k : requests){
            time+=abs(k-last);
            last = k;
        }
        return time;
    }
};
