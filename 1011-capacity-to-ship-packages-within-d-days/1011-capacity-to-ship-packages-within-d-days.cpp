class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int wei = 0;
        for(int n : weights){
            wei+=n;
        }
        int left = *max_element(weights.begin(), weights.end()); int right = wei;
        while(left<=right){
            int curr = left + (right-left)/2;
            if(possible(curr, weights, days)){
                cout<<curr<<endl;
                right = curr-1;
            } else {
                left = curr+1;
            }
        }
        return left;
    }

    bool possible(int& wei, vector<int>& weights, int days){
        int curr = 0;
        for(int n : weights){
            if(curr+n>wei){
                days--;
                if(days<=0)return false;
                curr = 0;
            }
            curr+=n;
        }
        return true;
    }
};