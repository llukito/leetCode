class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> lasers;
        for(string s : bank){
            int total = 0;
            for(char ch : s){
                if(ch == '1'){
                    total++;
                }
            }
            if(total != 0){
                lasers.push_back(total);
            }
        }
        int res  = 0;
        for(int i=0; i<(int)lasers.size()-1; i++){
            res+= lasers[i]*lasers[i+1];
        }
        return res;
    }
};