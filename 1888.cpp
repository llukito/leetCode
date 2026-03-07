class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int onesAtEven = 0; int onesAtOdd = 0;
        int zerosAtEven = 0; int zerosAtOdd = 0;
        for(int i = 0 ; i < n; i++){
            if(s[i] == '1'){
                if(i%2 == 0)onesAtEven++;
                else onesAtOdd++;
            } else {
                if(i%2 == 0)zerosAtEven++;
                else zerosAtOdd++;
            }
        }
        int res = min(onesAtOdd+zerosAtEven, onesAtEven+zerosAtOdd);
        for(int i = 0 ; i < n; i++){
            if(s[i] == '1'){
                swap(zerosAtEven, zerosAtOdd);
                onesAtEven--;
                swap(onesAtEven, onesAtOdd);
                if(n%2 == 1)onesAtEven++;
                else onesAtOdd++;
            } else {
                swap(onesAtEven, onesAtOdd);
                zerosAtEven--;
                swap(zerosAtEven, zerosAtOdd);
                if(n%2 == 1)zerosAtEven++;
                else zerosAtOdd++;
            }
            res = min(res, min(onesAtOdd+zerosAtEven, onesAtEven+zerosAtOdd));
        }
        return res;
    }
};
