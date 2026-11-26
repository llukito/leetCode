class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = 1;
        int start = 10;
        while(n){
            if(alice){
                if(start <= n && start !=0){
                    n-=start;
                } else {
                    return false;
                }
                alice = 0;
            } else {
                if(start <= n && start !=0){
                    n-=start;
                } else {
                    return true;
                }
                alice = 1;
            }
            start--;
        }
        return !alice;
    }
};
