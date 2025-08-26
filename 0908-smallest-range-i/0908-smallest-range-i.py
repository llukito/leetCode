class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        n = min(nums)
        m = max(nums)
        n+=k
        m-=k
        res = m-n
        if res<0 : return 0
        return res