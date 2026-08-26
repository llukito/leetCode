class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lefts = 0;
        int rights = 0;
        int any = 0;
        for(char ch : moves){
            if(ch == 'L'){
                lefts++;
            } else if(ch == 'R'){
                rights++;
            } else {
                any++;
            }
        }
        return max(abs(lefts-(rights+any)), abs(rights-(lefts+any)));
    }
};
