class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int curr = tickets[k];
        int res = 0;
        for(int i=0; i<curr; i++){
            for(int j=0; j<tickets.size(); j++){
                if(tickets[j]!=0){
                    res++;
                    tickets[j]--;
                }
                if(j==k && tickets[j]==0)return res;
            }
        }
        return res;
    }
};