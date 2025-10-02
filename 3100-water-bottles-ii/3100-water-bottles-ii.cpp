class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = 0;
        while(numBottles!=0){
            if(numExchange> numBottles){
                res+=numBottles;
                break;
            }
            res+=numExchange;
            numBottles-=numExchange;
            numBottles+=1;
            numExchange+=1;
        }
        return res;
    }
};