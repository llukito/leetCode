class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<pair<int, int>> gaps;

        gaps.push_back({0, startTime[0]});
        for (int i = 1; i < n; i++) {
            gaps.push_back({endTime[i - 1], startTime[i]});
        }
        gaps.push_back({endTime[n - 1], eventTime});

        int result = 0;

        for (int i = 0; i < n; i++) {
            int dur = endTime[i] - startTime[i];

            for (auto& gap : gaps) {
                int gStart = gap.first;
                int gEnd = gap.second;

                if (gEnd - gStart >= dur) {
                    int newStart = gStart;
                    result = max(result, simulateMove(i, newStart, eventTime, startTime, endTime));
                    int newEnd = gEnd;
                    result = max(result, simulateMove2(i, newEnd, eventTime, startTime, endTime));
                }
            }
        }

        return result;
    }

    int simulateMove(int idx, int newStart, int eventTime,
                     vector<int>& startTime, vector<int>& endTime) {
        int dur = endTime[idx] - startTime[idx];
        int newEnd = newStart + dur;

        vector<pair<int, int>> meetings;
        for (int j = 0; j < startTime.size(); ++j) {
            if (j == idx) continue;
            meetings.push_back({startTime[j], endTime[j]});
        }
        meetings.push_back({newStart, newEnd});
        sort(meetings.begin(), meetings.end());

        int maxGap = meetings[0].first;
        for (int j = 1; j < meetings.size(); j++) {
            maxGap = max(maxGap, meetings[j].first - meetings[j - 1].second);
        }
        maxGap = max(maxGap, eventTime - meetings.back().second);
        return maxGap;
    }

     int simulateMove2(int idx, int newEnd, int eventTime,
                     vector<int>& startTime, vector<int>& endTime) {
        int dur = endTime[idx] - startTime[idx];
        int newStart = newEnd - dur;

        vector<pair<int, int>> meetings;
        for (int j = 0; j < startTime.size(); ++j) {
            if (j == idx) continue;
            meetings.push_back({startTime[j], endTime[j]});
        }
        meetings.push_back({newStart, newEnd});
        sort(meetings.begin(), meetings.end());

        int maxGap = meetings[0].first;
        for (int j = 1; j < meetings.size(); j++) {
            maxGap = max(maxGap, meetings[j].first - meetings[j - 1].second);
        }
        maxGap = max(maxGap, eventTime - meetings.back().second);
        return maxGap;
    }
};
