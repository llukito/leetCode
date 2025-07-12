class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        for(int i=0; i<s.length(); i++){
            int moves = -1;
            check(moves, startPos[0], startPos[1], s.substr(i), n);
            res.push_back(moves == -1 ? 0 : moves);
        }
        return res;
    }

    void check(int& moves, int r, int c, string str, int n){
        if(!(r<n && r>=0 && c>=0 && c<n))return;
        moves++;
        if(str.empty())return;
        if(str[0] == 'L'){
            check(moves, r, c-1, str.substr(1), n);
        } else if(str[0] == 'R'){
            check(moves, r, c+1, str.substr(1), n);
        } else if(str[0] == 'D'){
            check(moves, r+1, c, str.substr(1), n);
        } else if(str[0] == 'U'){
            check(moves, r-1, c, str.substr(1), n);
        }
    }
};