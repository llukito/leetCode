class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int root=floor(sqrt(n));
        vector<int> v(root+2,0);
        for(int i=0;i<n;i++) { 
            v[i/root]=max(v[i/root],baskets[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            int ind=-1;
            for(int j=0;j<root+2;j++) {
                if(v[j]>=fruits[i]) {
                    ind=j;
                    break;
                }
            }
            if(ind==-1) {
                ans++;
                continue;
            }
            for(int j=root*ind;j<(ind+1)*root;j++) {
                if(baskets[j]>=fruits[i]) {
                    baskets[j]=0;
                    break;
                }
            }
            v[ind]=0; 
            for(int j=root*ind;j<min(n,(ind+1)*root);j++) {
                v[ind]=max(v[ind],baskets[j]);
            }
        }
        return ans;
    }
};