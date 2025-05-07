class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        unordered_map<char, int> edges;
         for(int i=0; i<garbage.size(); i++){
            for(char c : garbage[i]){
                edges[c] = i;
            }
         }
        unordered_map<int, char> map; map[0]='G'; map[1]='P'; map[2]='M';
        for(int i=0; i<=2; i++){
            char ch = map[i];
            int index = -1;
            for(int i=0; i<=edges[ch]; i++){
                if(index>=0){
                    res+=travel[index];
                }
                int total = get(garbage[i], ch);
                res+=total;
                index++;
            }
        }
        return res;
    }

    int get(string& str, char& ch){
        int t = 0;
        for(char c : str){
            if(c==ch)t++;
        }
        return t;
    }
};