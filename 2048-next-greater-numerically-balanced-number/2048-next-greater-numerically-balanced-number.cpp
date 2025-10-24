class Solution {
public:
    int nextBeautifulNumber(int n) {
        int size = to_string(n).size() + 1;
        int toAdd = size;
        int maxPossible = 0;
        while(size--){
            maxPossible*=10;
            maxPossible += toAdd;
        }

        int left = n+1; int right = maxPossible;
        for(int i=left; i<right; i++){
            if(valid(i)){
                return i;
            }
        }
        return right;
    }

    bool valid(int x){
        vector<int> count(10);
        while (x > 0) {
            count[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; ++d) {
            if (count[d] > 0 && count[d] != d) {
                return false;
            }
        }
        return true;
    }
};