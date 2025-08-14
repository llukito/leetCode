class UndergroundSystem {
public:
    unordered_map<string, unordered_map<string, vector<double>>> map;
    unordered_map<int, pair<string,int>> map2;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        map2[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        map[map2[id].first][stationName].push_back(t-map2[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double all = 0;
        for(double n : map[startStation][endStation]){
            all+=n;
        }
        return (double)all/map[startStation][endStation].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */