class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1[0]==0 && p1[1]==0 && p2[0]==0 && p2[1]==0 && p3[0]==0 && p3[1]==0 && p4[0]==0 && p4[1]==0)return false;
        vector<vector<int>> big; big.push_back(p1); big.push_back(p2); big.push_back(p3); big.push_back(p4);
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++){
                vector<int> pp1 = big[i];
                vector<int> pp2 = big[j];
                vector<int> pp3, pp4;
                for(int n = 0; n < 4; n++) {
                    if(n != i && n != j) {
                        if(pp3.empty()) pp3 = big[n];
                        else pp4 = big[n];
                    }
                }
                pair<int,int> pr1 ={pp1[0]+pp2[0],pp1[1]+pp2[1]};
                pair<int,int> pr2 ={pp3[0]+pp4[0],pp3[1]+pp4[1]};
                if(pr1==pr2){
                    pair<int,int> side1 ={abs(pp1[0]-pp3[0]),abs(pp1[1]-pp3[1])};
                    pair<int,int> side2 ={abs(pp2[0]-pp4[0]),abs(pp2[1]-pp4[1])};
                    pair<int,int> side3 ={abs(pp1[0]-pp4[0]),abs(pp1[1]-pp4[1])};
                    pair<int,int> side4 ={abs(pp2[0]-pp3[0]),abs(pp2[1]-pp3[1])};
                    pair<int,int> diag1 ={abs(pp1[0]-pp2[0]),abs(pp1[1]-pp2[1])};
                    pair<int,int> diag2 ={abs(pp4[0]-pp3[0]),abs(pp4[1]-pp3[1])};
                    long long size1 = pow(side1.first,2) + pow(side1.second,2);
                    long long size2 = pow(side2.first,2) + pow(side2.second,2);
                    long long size3 = pow(side3.first,2) + pow(side3.second,2);
                    long long size4 = pow(side4.first,2) + pow(side4.second,2);
                    long long dsize1 = pow(diag1.first,2) + pow(diag1.second,2);
                    long long dsize2 = pow(diag2.first,2) + pow(diag2.second,2);
                    return size1==size2 && size3==size4 && size1==size3 && dsize1==dsize2;
                }
            }
        }
        return false;
    }
};