class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int num=0;
        for(int n : hours){
            if(n>=target){
                num++;
            }
        }
        return num;
    }
};