class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = (int)dominoes.length();
        vector<int> arr(n, 0);
        int force = 0;
        int index = 0;
        for(char ch : dominoes){
            if(ch=='R'){
                force = n;
            } else if(ch=='L'){
                force = 0;
            } else {
                force = max(force-1, 0);
            }
            arr[index++] = force;
        }
        int force2 = 0;
        index = n-1;
        for(int i = n-1; i>=0; i--){
            char ch = dominoes[i];
            if(ch=='L'){
                force2 = n;
            } else if(ch=='R'){
                force2 = 0;
            } else {
                 force2 = max(force2-1, 0);
            }
            arr[index--]-=force2;
        }
        string result;
        for(int i : arr){
            if(i>0){
                result+='R';
            } else if(i<0){
                result+='L';
            } else {
                result+='.';
            }
        }
        return result;
    }
};