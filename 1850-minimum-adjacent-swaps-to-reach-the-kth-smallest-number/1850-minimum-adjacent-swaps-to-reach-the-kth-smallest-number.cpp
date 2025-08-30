class Solution {
public:
    int getMinSwaps(string num, int k) {
        string first = num;
        for(int i=0; i<k; i++){
            int idx1 = -1;
            for(int j=num.length()-2; j>=0; j--){
                if(num[j]<num[j+1]){
                    idx1 = j;
                    break;
                }
            }
            int idx2 = -1;
            for(int j=num.length()-1; j>=0; j--){
                if(num[j]>num[idx1]){
                    idx2 = j;
                    break;
                }
            }
            swap(num[idx1], num[idx2]);
            reverse(num.begin()+idx1+1, num.end());
        }
        int res = 0;
        unordered_map<char, int> map;
        for(int i=0; i<num.length(); i++){
            map[num[i]] = i;
        }
        return minAdjacentSwaps(first, num);
    }

    int minAdjacentSwaps(string str1, string str2) {
        string s1 = str1, s2 = str2;
        int n = s1.size();
        int swaps = 0;
        int i = n - 1, j = n - 1;
        while(i >= 0) {
            if(s1[i] == s2[j]) {
                i--, j--;
            } else {
                int k = i;
                // find matching char
                while(k >= 0 && s1[k] != s2[j]) k--;
                // bubble it to position i
                while(k < i) {
                    swap(s1[k], s1[k+1]);
                    swaps++;
                    k++;
                }
                i--, j--;
            }
        }
        return swaps;
    }

}; 