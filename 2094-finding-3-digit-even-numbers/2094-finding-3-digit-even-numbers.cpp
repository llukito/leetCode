class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> temp(10,0);
        for(int n : digits){
            temp[n]++;
        }   
        for(int i=100; i<999; i+=2){
            int n =i;
            vector<int> curr(10,0);
            curr[n%10]++; n/=10; 
            curr[n%10]++; n/=10; 
            curr[n%10]++; n/=10;
            bool b = true;
            for(int j =0; j<curr.size(); j++){
                if(curr[j] > temp[j]){
                    b = false; 
                    break;
                }
            } 
            if(b)result.push_back(i);
        }
        return result;
    }
};