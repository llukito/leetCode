class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> idx;
        for(int i=0; i<deck.size(); i++){
            idx.push_back(i);
        }
        vector<int> result(deck.size(), 0);
        for(int i : deck){
            int ind = idx.front(); idx.pop_front();
            result[ind] = i;
            if(!idx.empty()){
                idx.push_back(idx.front());
                idx.pop_front();
            }
        }
        return result;
    }
    
};