class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> uses(n, 0);
        priority_queue<int, vector<int>, greater<int>> rooms;
        for(int i=0; i<n; i++){
            rooms.push(i);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(vector<int> vect : meetings){
            cout<<vect[0]<<" "<<vect[1]<<endl;
            int start = vect[0]; int end = vect[1];
            while(!pq.empty() && pq.top().first <= start){
                rooms.push(pq.top().second);
                pq.pop();
            }
            if(!rooms.empty()){
                int room = rooms.top(); rooms.pop();
                uses[room]++;
                pq.push({end, room});
            } else {
                int room = pq.top().second; int endTime = pq.top().first; pq.pop();
                uses[room]++;
                pq.push({endTime+end-start, room});
            }
        }
        int maxUse = 0;
        int res = -1;
        for(int i=0; i<n; i++){
            cout<<i<<" uses : "<<uses[i]<<endl;
            if(uses[i]>maxUse){
                maxUse = uses[i];
                res = i;
            }
        }
        return res;
    }
};