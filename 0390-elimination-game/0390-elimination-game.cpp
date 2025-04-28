class Solution {
public:
    int lastRemaining(int n) {
        return lastOneStanding(1, n, n, true, 1);
    }

    int lastOneStanding(int start, int end, int size, bool b, int step){
        if(size == 1){
            return end;
        }
        if(b){
            if(size%2==1){
                end-=step;
            }
            start+=step;
            size/=2;
            return lastOneStanding(start, end, size, false, step*2);
        } else {
            if(size%2==1){
                start+=step;
            }
            end-=step;
            size/=2;
            return lastOneStanding(start, end, size, true, step*2);
        }
    }
};