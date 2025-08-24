class Solution:
    def splitNum(self, num: int) -> int:
        digits = [int(d) for d in str(num)]
        digits.sort()
        one = 0
        scn = 0
        b = True
        for n in digits:
            if(b):
                one*=10
                one+=n
                b = False
            else:
                scn*=10
                scn+=n
                b = True
        return scn+one