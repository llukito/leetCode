class Solution {
public:
    unordered_map<string, vector<string>> map;

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> vect;
        vector<string> curr;
        unordered_set<int> set;
        fill(words, groups, vect, curr, set, -1, 0, -1);
        return vect;
    }

    void fill(vector<string>& words, vector<int>& groups, vector<string>& res, vector<string>& curr, unordered_set<int>& set, int last, int index, int wordIndex){
        string key = to_string(last) + "#" + to_string(index) + "#" + to_string(wordIndex);
        if (map.count(key)) {
            if (curr.size() + map[key].size() <= res.size()) return;
        }
        if(curr.size() > res.size()){
            res = curr;
        }
        for(int i=index; i<words.size(); i++){
            if(!set.count(i)){
                if(last == -1 || last!=groups[i]){
                    if(curr.empty() || valid(curr.back(), words[i])){
                        set.insert(i);
                        curr.push_back(words[i]);
                        fill(words, groups, res, curr, set, groups[i], i, i );
                        set.erase(i);
                        curr.pop_back();
                    }
                }
            }
        }
        map[key] = vector<string>(res.begin() + curr.size(), res.end());
    }

    bool valid(string& s1, string& s2){
        if(s1.length()!=s2.length())return false;
        int v = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i]){
                v++;
            }
            if(v>2)return false;
        }
        return v == 1;
    }
};