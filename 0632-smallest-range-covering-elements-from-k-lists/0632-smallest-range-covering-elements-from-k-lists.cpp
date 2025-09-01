class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        unordered_map<int, unordered_set<int>> map;
        vector<int> vect;
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            for(int n : nums[i]){
                map[n].insert(i);
                if(!s.count(n)){
                    s.insert(n);
                    vect.push_back(n);
                }
            }
        }
        sort(vect.begin(), vect.end());
        int c = 0;
        int r = 0;
        int prev = vect[r]-1;
        vector<int> res(2,-1);
        unordered_map<int, int> size;
        while(c<=r && r < vect.size()){
            for(int i=prev+1; i<=vect[r]; i++){
                for(int n : map[i]){
                    size[n]++;
                }
            }
            prev = vect[r];
            if(size.size() == nums.size()){
                cout<<vect[c]<<" "<<vect[r]<<endl;
                if(res[0] == -1 && res[1] == -1){
                    res[0] = vect[c];
                    res[1] = vect[r];
                } else if(res[1]-res[0]>vect[r]-vect[c] || (res[1]-res[0] == vect[r]-vect[c] && res[0]>vect[c])){
                    res[0] = vect[c];
                    res[1] = vect[r];
                }
                if(c+1>r)break;
                for(int i=vect[c]; i<vect[c+1]; i++){
                    for(int n : map[i]){
                        size[n]--;
                        if(size[n]==0)size.erase(n);
                    }
                }
                c++;
            } else {
                r++;
            }
        }
        return res;
    }
};