class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        if(label == 1)return {1};
        vector<int> res;
        res.push_back(label);
        while(true){
            int maxTwos = get(label);
            int maxElement = pow(2,maxTwos)-1;
            int num = pow(2,maxTwos-1);
            int maxBefore = pow(2,maxTwos-1)-1;
            int minBefore = maxBefore - pow(2,maxTwos-2)+1;
            double curr = maxBefore;
            for(int i=maxElement-num+1; i<=maxElement; i++){
                if(i == label){
                    res.push_back((int)(curr+0.5));
                    break;
                } else {
                    curr-=0.5;
                }
            }
            label = res.back();
            if(label <= 1){
                break;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int get(int label){
        int res = 1;
        int curr = 1;
        while(curr<label){
            curr*=2;
            if(curr > label)return res;
            res++;
        }
        return res;
    }
};