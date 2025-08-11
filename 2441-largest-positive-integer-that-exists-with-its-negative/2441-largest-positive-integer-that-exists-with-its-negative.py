class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        res = -1
        for n in nums:
            if n>0 and -n in nums :
                res = max(res, n)
        return res
