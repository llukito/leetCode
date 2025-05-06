class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vect1;
        vector<int> vect2;
        stringstream ss(version1);
        string token;
        while(getline(ss,token,'.')){
            vect1.push_back(stoi(token));
        }
        stringstream ss2(version2);
        string token2;
        while(getline(ss2,token2,'.')){
            vect2.push_back(stoi(token2));
        }   
        if(vect1.size()>vect2.size()){
            int num = vect1.size()-vect2.size();
            for(int i=0; i<num; i++){
                vect2.push_back(0);
            }
        } else if(vect1.size()<vect2.size()){
            int num = vect2.size()-vect1.size();
            for(int i=0; i<num; i++){
                vect1.push_back(0);
            }
        }

        for(int i=0; i<vect1.size(); i++){
            if(vect1[i]<vect2[i]){
                return -1;
            } else if(vect1[i]>vect2[i]){
                return 1;
            }
        }
        return 0;
    }
};