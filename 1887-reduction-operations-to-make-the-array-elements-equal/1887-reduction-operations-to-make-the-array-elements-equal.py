class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort(reverse = True)
        lar = 0
        v = 0
        slar = 0
        res  = 0
        for i in range(len(nums)):
            if(lar==0 or lar == nums[i]):
                v+=1
                lar = nums[i]
            else:
                slar = nums[i]
                res +=v
                v+=1
                lar = slar
                slar = 0
        return res