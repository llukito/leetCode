class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char ch1 = x>=y ? 'a' : 'b';
        char ch2 = x>=y ? 'b' : 'a';
        int first = max(x,y);
        int second = min(x,y);
        string stk1;
        int res = 0;
        for(char ch :s){
            stk1.push_back(ch);
            int size = stk1.size();
            if(size>=2 && stk1[size-1] == ch2 && stk1[size-2] == ch1){
                res+=first;
                stk1.pop_back();
                stk1.pop_back();
            }
        }
        string stk2;
        for(char ch :stk1){
            stk2.push_back(ch);
            int size = stk2.size();
            if(size>=2 && stk2[size-1] == ch1 && stk2[size-2] == ch2){
                res+=second;
                cout<<second<<" "<<endl;
                stk2.pop_back();
                stk2.pop_back();
            }
        }
        return res;
    }
};