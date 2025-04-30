class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vect;
        for(int i=1; i<=n; i++){
            vect.push_back(i);
        }
        return winner(vect,k, 0);
    }

    int winner(vector<int>& vect, int& k, int index){
        if(vect.size()==1){
            return vect[0];
        }
        int removed = (index + k-1)%vect.size();
        vect.erase(vect.begin()+removed);
        return winner(vect, k, (removed));
    }
};