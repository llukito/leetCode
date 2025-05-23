class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> nums(26, 0);
        for(char ch : s){
            nums[ch-'a']++;
        }
        int v = 0; int c = 0;
        for(int i=0; i<26; i++){
            if(isVowel(i)){
                v = max(v, nums[i]);
            } else {
                c = max(c, nums[i]);
            }
        }
        return v+c;
    }

    bool isVowel(int ch){
        return ch=='a'-'a' || ch=='e'-'a' || ch=='i'-'a' ||
                ch == 'o'-'a' || ch == 'u'-'a';
    }
};