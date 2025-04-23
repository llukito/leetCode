class Solution {
public:
    int minBitFlips(int start, int goal) {
        string bStart  = getBInary(start);
        string bGoal  = getBInary(goal);
        if(bStart.size()<bGoal.size()){
            int difference = bGoal.size()-bStart.size();
            for(int i=0; i<difference; i++){
                bStart.insert(bStart.begin(),'0');
            }
        } else if(bGoal.size()<bStart.size()){
            int difference = bStart.size()-bGoal.size();
            for(int i=0; i<difference; i++){
                bGoal.insert(bGoal.begin(),'0');
            }
        }
        int num = 0;
        for(int i=0; i<bStart.size(); i++){
            if(bStart[i]!=bGoal[i])num++;
        }
        return num;
    }

    string getBInary(int n){
        string res;
        while(n!=0){
            if(n%2==0){
                res+='0';
            } else {
                res+='1';
            }
            n/=2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};