class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        sums = 0
        for n in nums:
            sums+=n
        ops = 0
        while(sums!=0):
            ops+=1
            n = self.getMin(nums)
            for i in range(len(nums)):
                if(nums[i]>0):
                    nums[i]-=n
                    sums-=n
        return ops
    
    def getMin(self, nums):
        val = float('inf')
        for n in nums:
            if(n!=0):
                val = min(val, n)
        return val