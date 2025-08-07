class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int tested = 0;
        for(int i=0; i<batteryPercentages.size(); i++){
            int n = batteryPercentages[i];
            if(n>0){
                tested++;
                for(int j=i+1; j<batteryPercentages.size(); j++){
                    batteryPercentages[j] = max(0, batteryPercentages[j]-1);
                }
            }
        }
        return tested;
    }
};