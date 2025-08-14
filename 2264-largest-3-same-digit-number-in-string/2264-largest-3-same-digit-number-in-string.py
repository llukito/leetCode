class Solution:
    def largestGoodInteger(self, num: str) -> str:
        left = 0
        res = 0
        fin = ""
        while left+2 < len(num):
            if(num[left] == num[left+1] and num[left+1]==num[left+2]):
                if(int(num[left : left+3]) >= res):
                    res = int(num[left : left+3])
                    fin = num[left : left+3]
            left+=1
        return fin

