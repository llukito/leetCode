class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)return 1;
        bitset<32> b(n);
        string str = b.to_string();
        str = str.substr(str.find('1'));
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '0'){
                str[i] = '1';
            } else {
                str[i] = '0';
            }
        }
        return stoi(str, 0, 2);
    }
};
