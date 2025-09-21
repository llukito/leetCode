class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int,int>>> mp;
    unordered_map<int, unordered_map<int,int>> stores;
    set<pair<int,pair<int,int>>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& entry : entries){
            int shop = entry[0]; int movie = entry[1]; int price = entry[2];
            mp[movie].insert({price, shop});
            stores[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> vect;
        for(auto& entry : mp[movie]){
            vect.push_back(entry.second);
            if(vect.size() == 5)break;
        }
        return vect;
    }
    
    void rent(int shop, int movie) {
        mp[movie].erase({stores[shop][movie], shop});
        rented.insert({stores[shop][movie], {shop, movie}});
    }
    
    void drop(int shop, int movie) {
        mp[movie].insert({stores[shop][movie], shop});
        rented.erase({stores[shop][movie], {shop, movie}});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> vect;
        for(auto& entry : rented){
            vect.push_back({entry.second.first, entry.second.second});
            if(vect.size()==5)break;
        }
        return vect;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */