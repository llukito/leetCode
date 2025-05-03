class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> set;
        for(vector<int> vect : prerequisites){
            set.insert(vect[0]);
        }
        unordered_set<int> stock;
        for(int i=0; i<numCourses; i++){
            if(!set.count(i)){
                stock.insert(i);
            }
        }
        return can(prerequisites, stock, numCourses);
    }

    bool can(vector<vector<int>>& prerequisites, unordered_set<int>& stock, int& n){
        int size = stock.size();
        if(size == n)return true;
        for(vector<int> vect : prerequisites){
            if(stock.count(vect[1])){
                stock.insert(vect[0]);
            }
        }
        if(size == stock.size())return false;
        return can(prerequisites, stock, n);
    }
};