class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for(int i=0; i<k; i++){
            sort(gifts.begin(), gifts.end(), greater<int>());
            gifts[0]=(int)sqrt(gifts[0]);
        }
        long long sum = 0;
        for(int n : gifts){
            sum+=n;
        }
        return sum;
    }
};