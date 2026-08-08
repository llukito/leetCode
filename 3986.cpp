class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hours = stoi(startTime.substr(0, 2) )- stoi(endTime.substr(0, 2));
        int mins = stoi(startTime.substr(3, 2) )- stoi(endTime.substr(3, 2));
        int secs = stoi(startTime.substr(6, 2) )- stoi(endTime.substr(6, 2));
        return -1*(hours*3600 + mins*60 + secs);
    }
};
