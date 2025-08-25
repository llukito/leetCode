class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        res = []
        gray = []
        for i in range(pow(2,n)):
            gray.append(i^(i>>1))
        idx = -1
        for i in range(len(gray)):
            if gray[i] == start :
                idx = i
                break
        for i in range(pow(2,n)):
            res.append(gray[(idx+i)%(pow(2,n))])
        return res
