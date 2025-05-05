class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string word;
        int n = 0;
        while(ss>>word){
            n++;
        }
        return n;
    }
};