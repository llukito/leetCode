class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        currFirst = 0
        currSecond = 0
        b = True
        res = 0
        bb = False
        bul = True
        bn = False
        for i in range(len(nums)):
            if(nums[i]==1):
                bn = True
                if b :
                    currFirst +=1
                else:
                    currSecond+=1
            else:
                bul = False
                if(b and bn):
                    b = False
                if(bb):
                    res = max(res, currFirst+currSecond)
                    currFirst = currSecond
                    currSecond = 0
                res = max(res, currFirst)
                res = max(res, currSecond)
                if (i+1 < len(nums) and nums[i+1]==1 and i-1>=0 and nums[i-1]==1):
                    bb = True
                else:
                    bb = False
        if bul : return currFirst-1
        if(bb):
            res = max(res, currFirst+currSecond)
        return res