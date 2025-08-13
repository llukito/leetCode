class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n<=0 : return False
        return self.trans(n)

    
    def trans(self, n: int) -> bool:
        res = ""
        while n!=0 :
            res+=str(n%3)
            n//=3
        r = ""
        ones = 0
        for i in range(len(res)-1, -1, -1):
            if res[i] == '1':ones+=1
            if res[i] == '2':return False
            if ones>1 : return False
        return ones == 1
