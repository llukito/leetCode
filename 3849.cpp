class Solution {
public:
    string maximumXor(string s, string t) {
        int arr[2] = {0,0};
        for(char ch : t){
            arr[ch-'0']++;
        }
        string res;
        for(char ch : s){
            if(ch == '1'){
                if(arr[0]!=0){
                    res+='1';
                    arr[0]--;
                } else {
                    res+='0';
                    arr[1]--;
                }
            } else {
                if(arr[1]!=0){
                    res+='1';
                    arr[1]--;
                } else {
                    res+='0';
                    arr[0]--;
                }
            }
        }
        return res; 
    }
};
