class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for(vector<int> vect : queries){
            // int n = count(vect);
            int n = test(vect);
            res+=n;
        }
        return res;
    }

    long long test(vector<int> vect){
        int d = 0;
        for(int i=vect[0]; i<=vect[1]; i++){
            d+=floor(log4(i))+1;
        }
        return (d+1)/2;
    }

    long long count(vector<int> vect){
        priority_queue<int> pq;
        for(int i=vect[0]; i<=vect[1]; i++){
            pq.push(floor(log4(i))+1);
        }
        long long curr = 0;
        while(!pq.empty()){
            curr++;
            int p = pq.top();
            pq.pop();
            if(!pq.empty()){
                int pp = pq.top();
                pq.pop();
                if(pp-1 != 0){
                    pq.push(pp-1);
                }
            }
            if(p-1 != 0){
                pq.push(p-1);
            }
        }
        return curr;
    }

    double log4(int i){
        return log(i) / log(4.0);
    }
};