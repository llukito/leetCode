class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
        for(int i=lo; i<=hi; i++){
            pq.push({power(i),i});
        }
        for(int i=0; i<k-1; i++){
            pq.pop();
        }
        return pq.top().second;
    }

    int power(int n){
        int steps = 0;
        while(n!=1){
            if(n%2==0){
                n/=2;
            } else{
                n = 3*n +1;
            }
            steps++;
        }
        return steps;
    }
};