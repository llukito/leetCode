class Solution {
public:
    string vowels = "aeiou";
    int countVowelStrings(int n) {
        int res = 0;
        string curr="";
        fill(curr, res, n);
        return res;
    }

    void fill(string& curr, int& res, int n){
        if(curr.length() == n){
            res++;
            return;
        }
        for(char ch : vowels){
            if(curr.empty() || curr.back() <= ch){
                curr+=ch;
                fill(curr, res, n);
                curr.pop_back();
            }
        }
    }
};