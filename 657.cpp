class Solution {
public:
    bool judgeCircle(string moves) {
        int numOfRight = 0;
        int numOfLeft = 0;
        int numOfDown = 0;
        int numOfUp = 0;
        for(char ch : moves){
            if(ch == 'R'){
                numOfRight++;
            } else if(ch == 'L'){
                numOfLeft++;
            } else if(ch == 'U'){
                numOfUp++;
            } else {
                numOfDown++;
            }
        }
        return numOfRight == numOfLeft && numOfUp == numOfDown;
    }
};
