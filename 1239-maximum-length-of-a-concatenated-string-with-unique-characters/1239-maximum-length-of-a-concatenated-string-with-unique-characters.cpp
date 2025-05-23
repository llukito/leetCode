class Solution {
public:
    int maxLength(vector<string>& arr) {
        set<char> st;
        unordered_set<int> indexes;
        unordered_map<string, int> map;
        int res = 0;
        fill(arr, st, res, indexes, map);
        return res;
    }

    void fill(vector<string>& arr, set<char>& st, int& res, unordered_set<int>& indexes, unordered_map<string, int>& map){
        string key = getKey(st);
        if(map.count(key)){
            return;
        }
        map[key] = st.size();
        res = max(res, (int)st.size());
        for(int i=0; i<arr.size(); i++){
            if(!indexes.count(i)){
                indexes.insert(i);
                bool b = true;
                set<char> th = st;
                for(char ch : arr[i]){
                    if(!th.count(ch)){
                        th.insert(ch);
                    } else {
                        b = false;
                        break;
                    }
                }
                if(b){
                    fill(arr, th, res, indexes, map);
                }
                indexes.erase(i);
            }
        }
    }

    string getKey(set<char>& st){
        string res;
        for(char ch : st){
            res+=ch;
        }
        return res;
    }
};