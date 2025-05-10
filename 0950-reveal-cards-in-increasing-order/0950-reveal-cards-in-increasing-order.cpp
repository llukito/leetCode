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
    
    void fill(vector<int>& deck, vector<int>& result, unordered_set<int>& set, int& last ){
        if(result.size() == deck.size()){
            return;
        }
        for(int i=0; i<deck.size(); i++){
            int n = deck[i];
            int m = deck[(i+1)%deck.size()];
            if(!set.count(n) && n>last){
                set.insert(n);
                result.push_back(n);
                fill(deck, result, set, n);
                set.erase(n);
                result.pop_back();
            }
        }
    }
};