class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;

        vector<int> count(n, 0);

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];

            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                busy.push({end, room});
                count[room]++;
            } else {
                auto [t, room] = busy.top();
                busy.pop();
                busy.push({t + (end - start), room});
                count[room]++;
            }
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[res]) {
                res = i;
            }
        }
        return res;
    }
};
