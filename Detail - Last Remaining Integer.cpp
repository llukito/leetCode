class Solution {
public:
    #define ll long long
    long long lastInteger(long long n) {
        ll allNumbers = n;
        ll first = 1;
        int dir = 1; // if 1 we are going right, if -1 left
        long long steps = 1;
        while(allNumbers!=1){
            if(dir == 1){ 
                // first remains unchanged
            } else {
                if(allNumbers % 2 == 0){
                    cout<<"here"<<endl;
                    first += steps;
                } // else first survives
            }
            allNumbers-=allNumbers/2;
            dir*=-1;
            steps*=2;
        }
        return first;
    }
};
