class Solution {
public:
    int numTilePossibilities(string tiles) {
        int num = 0;
        string str;
        unordered_set<int> set;
        unordered_set<string> s;
        fill(set, tiles, 0, str, s);
        return s.size()-1;
    }

    void fill(unordered_set<int>& set, string tiles, int index, string& str, unordered_set<string>& s){
        if(str.length()>tiles.length())return;
        s.insert(str);
        for(int i=0; i<tiles.length(); i++){
            if(!set.count(i)){
                set.insert(i);
                str+=tiles[i];
                fill(set, tiles, index, str, s);
                str.pop_back();
                set.erase(i);
            }
        }
    }
};