class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        res = []
        xk = king[0]
        yk = king[1]
        x = xk
        y = yk
        while xk < 8 :
            l = [xk, yk]
            if l in queens:
                res.append(l)
                break
            xk+=1
        xk = x
        while xk >=0 :
            l = [xk, yk]
            if l in queens:
                res.append(l)
                break
            xk-=1
        xk = x
        while yk < 8 :
            l = [xk, yk]
            if l in queens:
                res.append(l)
                break
            yk+=1
        yk = y
        while yk >=0 :
            l = [xk, yk]
            if l in queens:
                res.append(l)
                break
            yk-=1
        yk = y
        while yk >=0 and yk<8 and xk>=0 and xk<8 :
            l = [xk, yk]
            if l in queens:
                res.append(l)
                break
            yk-=1
            xk-=1
        yk = y
        xk = x
        while yk >=0 and yk<8 and xk>=0 and xk<8 :
            l = [xk, yk]
            if l in queens:
                res.append(l)
                break
            yk+=1
            xk+=1
        yk = y
        xk = x
        while yk >=0 and yk<8 and xk>=0 and xk<8 :
            l = [xk, yk]
            if l in queens:
                res.append(l)
                break
            yk-=1
            xk+=1
        yk = y
        xk = x
        while yk >=0 and yk<8 and xk>=0 and xk<8 :
            l = [xk, yk]
            if l in queens:
                res.append(l)
                break
            yk+=1
            xk-=1
        yk = y
        xk = x
        return res
