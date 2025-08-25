class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        lis = []
        for i in range(len(plantTime)):
            lis.append([growTime[i], plantTime[i]])
        lis.sort(reverse = True)
        res = 0
        m = 0
        for n in lis:
            res+=n[1]
            m = max(m, res+n[0])
        res=max(m,res+lis[-1][0])
        return res
