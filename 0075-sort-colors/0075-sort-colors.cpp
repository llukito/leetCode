class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        mySort(nums);
    }

    void mySort(vector<int>& nums){
        if(nums.size()<=1){
            return;
        }
        vector<int> vect1, vect2;
        for(int i=0; i<nums.size()/2; i++){
            vect1.push_back(nums[i]);
        }
        for(int i=nums.size()/2; i<nums.size(); i++){
            vect2.push_back(nums[i]);
        }
        mySort(vect1);
        mySort(vect2);
        merge(vect1, vect2, nums);
    }

    void merge(vector<int>& vect1, vector<int>& vect2, vector<int>& nums){
        deque<int> d1(vect1.begin(), vect1.begin());
        deque<int> d2(vect2.begin(), vect2.begin());
        while(!d1.empty() && !d2.empty()){
            if(d1.front()<d2.front()){
                nums.push_back(d1.front()); d1.pop_front();
            } else {
                nums.push_back(d2.front()); d2.pop_front();
            }
        }
        while(!d1.empty()){
            nums.push_back(d1.front()); d1.pop_front();
        }
        while(!d2.empty()){
            nums.push_back(d2.front()); d2.pop_front();
        }
    }
};