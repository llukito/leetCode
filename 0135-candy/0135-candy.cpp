class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> vect(ratings.size(), 1);
        for(int i=0; i<ratings.size(); i++){
            int mx = 1;
            if((i+1 < ratings.size() && ratings[i]>ratings[i+1])){
                mx = max(mx, vect[i+1]+1);
            }
            if((i-1>=0 && ratings[i]>ratings[i-1])){
                mx = max(mx, vect[i-1]+1);
            }
            vect[i] = mx;
        }
        for(int i=ratings.size()-1; i>=0; i--){
            if((i+1 < ratings.size() && ratings[i]>ratings[i+1])){
                if(vect[i]<=vect[i+1]){
                    vect[i]++;
                }
            }
            if((i-1>=0 && ratings[i]>ratings[i-1])){
                if(vect[i]<=vect[i-1]){
                    vect[i]++;
                }
            }
        }
        int candies = 0;
        for(int n : vect){
            cout<<n<<" ";
            candies+=n;
        }
        return candies;
    }
};