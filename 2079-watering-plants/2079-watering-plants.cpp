class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int curr = capacity;
        int steps = 0;
        for(int i=0; i<plants.size(); i++){
            if(curr<plants[i]){
                steps+=i+i;
                curr = capacity;
            }
            steps++;
            curr-=plants[i];
        }
        return steps;
    }
};