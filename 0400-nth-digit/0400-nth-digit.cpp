class Solution {
public:
    int findNthDigit(int n) {
        for(int d=1; true; d++){
            long long count = 9 * pow(10,d-1) * d;
            if(n-count<=0){
                int start = static_cast<int>(pow(10, d - 1));
                while(true){
                    string str = to_string(start);
                    if(n-d<=0){
                        return str[n-1]-'0';
                    }
                    n-=d;
                    start++;
                }
            }   
            n-=count;
        }
    }
};