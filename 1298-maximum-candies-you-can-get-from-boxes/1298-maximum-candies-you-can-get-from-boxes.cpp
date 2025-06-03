class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) { 
        unordered_set<int> keyStock;
        int res = 0;
        check(status, candies, keys, keyStock, containedBoxes, initialBoxes, res);
        return res;
    }

    void check(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, unordered_set<int>& keysStock, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes, int& res){
        int num = 0;
        vector<int> boxesStock;
        for(int n : initialBoxes){
            if(status[n] || keysStock.count(n)){
                num+=candies[n];
                for(int box : containedBoxes[n]){
                    boxesStock.push_back(box);
                }
                for(int key : keys[n]){
                    keysStock.insert(key);
                }
            } else {
                boxesStock.push_back(n);
            }
        }   
        if(num == 0){
            return;
        }
        res+=num;
        check(status, candies, keys, keysStock, containedBoxes, boxesStock, res); 
    }
};