class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        keys.insert(0);
        return check(rooms, keys);
    }

    bool check(vector<vector<int>>& rooms, unordered_set<int>& keys){
        if(keys.size() == rooms.size())return true;
        int size = keys.size();
        for(int n : keys){
            for(int num : rooms[n]){
                keys.insert(num);
            }
        }
        if(size == keys.size())return false;
        return check(rooms, keys);
    }
};