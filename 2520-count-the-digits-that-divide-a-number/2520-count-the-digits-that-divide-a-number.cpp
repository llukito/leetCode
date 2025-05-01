class Solution {
public:
    int countDigits(int num) {
        string str = to_string(num);
        int res=0;
        for(char ch : str){
            int n = ch-'0';
            if(num%n==0)res++;
        }
        return res;
    }
};