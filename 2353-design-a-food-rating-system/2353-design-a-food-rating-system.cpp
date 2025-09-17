class FoodRatings {
public:
    unordered_map<string, unordered_map<string, int>> bigMap;
    unordered_map<string, string> map;
    unordered_map<string, pair<string,int>> rats;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            bigMap[cuisines[i]][foods[i]] = ratings[i];
            if(rats[cuisines[i]].second < ratings[i]){
                rats[cuisines[i]] = {foods[i], ratings[i]};
            } else if(rats[cuisines[i]].second == ratings[i] && foods[i]<rats[cuisines[i]].first){
                rats[cuisines[i]] = {foods[i], ratings[i]};
            }
            map[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = map[food];
        bigMap[cuisine][food] = newRating;
        if(rats[cuisine].second < newRating){
            rats[cuisine] = {food, newRating};
        }else if(rats[cuisine].second == newRating && food<rats[cuisine].first){
            rats[cuisine] = {food, newRating};
        } else if(rats[cuisine].first == food && rats[cuisine].second > newRating){
            rats.erase(cuisine);
            int newVal = 0;
            string newStr = "";
            for(auto& entry : bigMap[cuisine]){
                if(entry.second > newVal){
                    newVal = entry.second;
                    newStr = entry.first;
                } else if(entry.second == newVal && entry.first < newStr){
                    newStr = entry.first;
                }
            }
            rats[cuisine] = {newStr, newVal};
        }
    }
    
    string highestRated(string cuisine) {
        return rats[cuisine].first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */