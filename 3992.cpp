class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int num_of_x = 0;
        int num_of_y = 0;
        for(char ch : s){
            if(ch == x){
                num_of_x++;
            } else if(ch == y){
                num_of_y++;
            }
        }
        string res = "";
        for(int i = 0; i < num_of_y; i++){
            res+=y;
        }
        for(int i = 0; i < num_of_x; i++){
            res+=x;
        }

        for(char ch : s){
            if(ch != x && ch != y){
                res+=ch;
            }
        }
        return res;
    }
};
