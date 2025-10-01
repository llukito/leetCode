class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int res = 0;
        while(numBottles!=0){
            res+=numBottles;
            empty+=numBottles;
            numBottles = 0;
            numBottles+= empty/numExchange;
            empty-=numExchange * numBottles;
        }
        return res;
    }
};

