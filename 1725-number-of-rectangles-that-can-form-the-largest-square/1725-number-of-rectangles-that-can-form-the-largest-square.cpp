class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int count = 0;
        int val = -1;
        for(vector<int> vect : rectangles){
            int v = min(vect[0], vect[1]);
            if(val < v){
                val =v;
                count = 1;
            } else if(val == v){
                count++;
            }
        }
        return count;
    }
};