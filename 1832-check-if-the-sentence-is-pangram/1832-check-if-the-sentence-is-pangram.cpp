class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<int> set;
        for(char ch : sentence){
            set.insert(ch);
        }
        return set.size()==26;
    }
};