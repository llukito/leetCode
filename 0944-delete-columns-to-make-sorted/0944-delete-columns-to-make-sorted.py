class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        r = 0
        for i in range(len(strs[0])):
            ch = chr(ord('a') - 1)
            b = False
            for str in strs:
                if str[i]<ch :
                    b = True
                    break
                ch = str[i]
            if b :
                r+=1
        return r



        