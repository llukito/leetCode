class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int val = 0;
        unordered_set<int> s{ 2, 3, 5, 7, 11, 13, 17, 19};
        for(int i = left; i<=right; i++){
            int n = get(i);
            if(s.count(n)){
                val++;
            }
        }
        return val;
    }

    int get(int n){
        int num = 0;
        while(n!=0){
            if(n%2 == 1){
                num++;
            }
            n/=2;
        }
        return num;
    }
};