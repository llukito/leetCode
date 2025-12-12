class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
            [](const vector<string>& a, const vector<string>& b) {
                int ta = stoi(a[1]);
                int tb = stoi(b[1]);

                if (ta != tb) return ta < tb;

                bool aIsOffline = (a[0] == "OFFLINE");
                bool bIsOffline = (b[0] == "OFFLINE");

                return aIsOffline > bIsOffline; 
            }
        );

        unordered_map<string, int> offline; unordered_set<string> online;
        for(int i = 0; i < numberOfUsers; i++) online.insert(to_string(i));
        vector<int> vect(numberOfUsers, 0);
        for(auto& entry : events){
            if(entry[0] == "MESSAGE"){
                for(auto& en : offline){
                    if(en.second + 60 <= stoi(entry[1])){
                        online.insert(en.first);
                    }
                }
                string currRes = "";
                int currAv = 0;
                if(entry[2] == "ALL"){
                    for(int i = 0; i < numberOfUsers; i++) vect[i]++;
                } else if(entry[2] == "HERE"){
                    for(string i : online)  vect[stoi(i)]++;
                } else {
                    for(int i = 0; i < entry[2].size(); i++){
                        if(entry[2][i] == 'd'){
                            i++;
                            while(entry[2][i] != ' ' && i < entry[2].size()){
                                currRes+=entry[2][i];
                                i++;
                            }
                            vect[stoi(currRes)]++;
                            currRes = "";
                        }
                    }
                }
            } else {
                online.erase(entry[2]);
                offline[entry[2]] = stoi(entry[1]);
            }
        }

        return vect;
    }
};