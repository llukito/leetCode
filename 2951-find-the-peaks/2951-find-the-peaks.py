class Solution:
    def findPeaks(self, mountain: List[int]) -> List[int]:
        res = []
        for i in range(len(mountain)):
            if i!=0 and i!=len(mountain)-1 and (i-1<0 or mountain[i-1]<mountain[i]) and (i+1>=len(mountain) or mountain[i+1]<mountain[i]): res.append(i)
        return res