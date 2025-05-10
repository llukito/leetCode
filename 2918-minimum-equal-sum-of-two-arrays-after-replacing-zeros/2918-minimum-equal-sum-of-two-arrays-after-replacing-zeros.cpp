class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeros1 = 0; int zeros2 = 0;
        int sum1 = 0; int sum2 = 0;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]==0){
                zeros1++;
                nums1[i]=1;
            }
            sum1+=nums1[i];
        }
        for(int i=0; i<nums2.size(); i++){
            if(nums2[i]==0){
                zeros2++;
                nums2[i]=1;
            }
            sum2+=nums2[i];
        }
        if(sum1 == sum2)return sum1;
        if(sum1 > sum2){
            if(zeros2 !=0){
                return sum1;
            }
            return -1;
        } else {
            if(zeros1 !=0){
                return sum2;
            }
            return -1;
        }
    }
};