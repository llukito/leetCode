class Solution {
public:
    bool isAnagram(string s, string t) {
        int array[26] = {}; // initialize elements to 0
        for (char ch : s) {
            array[ch - 'a']++;
        }
        for (char ch : t) {
            array[ch - 'a']--;
        }
        for (int n : array) {
            if (n != 0)return false;
        }
        return true;
    }
};