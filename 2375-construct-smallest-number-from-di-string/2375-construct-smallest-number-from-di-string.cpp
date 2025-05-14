class Solution {
public:
    string smallestNumber(string pattern) {
        int size = pattern.length()+1;
        string str;
        string curr;
        unordered_set<int> set;
        check(pattern, size, curr, str, set);
        return str;
    }

    void check(string& pattern, int& size, string& curr, string& str, unordered_set<int>& set){
        if(curr.length() == size){
            if(str.empty() || curr < str){
                  str = curr;
            }
            return;
        }
        for(int i=1; i<=9; i++){
            if(!set.count(i) && (curr.empty() || valid(curr, pattern, i))){
                set.insert(i);
                curr+=to_string(i);
                check(pattern, size, curr, str, set);
                curr.pop_back();
                set.erase(i);
            }
        }
    }

    bool valid(string& curr, string& pattern, int& i){
        int index = curr.length()-1;
        if(pattern[index]=='I'){
            if(curr[index]-'0'>=i)return false;
        } else {
            if(curr[index]-'0'<=i)return false;
        }
        return true;
    }
};