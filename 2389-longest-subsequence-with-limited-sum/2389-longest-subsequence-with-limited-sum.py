class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        prefix = [0 for _ in range(len(nums)+1)]
        for i in range(1,len(nums)+1):
            prefix[i] = prefix[i-1]+nums[i-1]
        res = []
        for n in queries:
            idx = bisect.bisect_right(prefix, n)
            res.append(idx-1)
        return res
