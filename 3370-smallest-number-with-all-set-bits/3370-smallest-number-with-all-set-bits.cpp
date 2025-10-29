class Solution {
public:
    int smallestNumber(int n) {
        bitset<32> b(n);               
        string s = b.to_string();       
        s = s.substr(s.find('1'));
        for(char& ch : s){
            ch='1';
        }
        return stoi(s,nullptr, 2);  
    }
};