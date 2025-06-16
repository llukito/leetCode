class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string tmp = fill(n);
        cout<<tmp<<endl;
        uint32_t res = 0;
        for(int i=0; i<tmp.size(); i++){
            int b = tmp[i]-'0';
            uint32_t power = pow(2,tmp.size()-i-1);
            res+= b*power;
        }
        return res;
    }
    
    string fill(uint32_t n){
        string str ="";
        while(n!=0){
            if(n%2==0){
                str+='0';
            } else {
                str+='1';
            }
            n/=2;
        }
        int size = str.size();
        if(size != 32){
             str.insert(size, 32-size, '0');
        }
        return str;
    }
};