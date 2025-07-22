class Solution {
public:
    int partitionString(string s) {
        unordered_set<int> set;
        int res = 0;
        for(char ch : s){
            if(set.count(ch)){
                res++; set.clear(); set.insert(ch);
            } else {
                set.insert(ch);
            }
        }
        return res+1;
    }
};