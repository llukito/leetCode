class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        s = set()
        for n in nums:
            for i in range(n[0], n[1]+1):
                s.add(i)
        return len(s)