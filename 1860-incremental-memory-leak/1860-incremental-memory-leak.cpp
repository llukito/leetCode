class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int time = 0;
        int i=1;
        while(true){
            time++;
            if(max(memory1, memory2) >= i){
                if(memory1 >= memory2)memory1-=i;
                else memory2-=i;
            }else {
                break;
            }
            i++;
        }
        return {time, memory1, memory2};
    }
};