class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse = True)
        res = []
        curr = 0
        currSum = 0
        for n in nums:
            currSum+=n
        for n in nums:
            curr+=n
            res.append(n)
            if(curr > currSum-curr):return res
        return res