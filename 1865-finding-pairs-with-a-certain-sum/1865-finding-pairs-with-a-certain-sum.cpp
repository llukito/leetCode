class FindSumPairs {
public:
    vector<int> vect1;
    vector<int> vect2;
    unordered_map<int, int> map;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vect1 = vector<int>(nums1.begin(), nums1.end());
        vect2 = vector<int>(nums2.begin(), nums2.end());
        for(int n : vect2){
            map[n]++;
        }
    }
    
    void add(int index, int val) {
        int temp = vect2[index];
        map[temp]--;
        map[temp+val]++;
        vect2[index]+=val;
    }
    
    int count(int tot) {
        int res = 0;
        for(int n : vect1){
            int m = tot-n;
            if(map.count(m)){
                res+=map[m];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */