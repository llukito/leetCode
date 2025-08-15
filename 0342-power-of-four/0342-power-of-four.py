class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n==0 : return False
        ones = 0
        while n!=0 :
            rem = n%4
            if(rem == 1) :
                ones+=1
                if ones > 1 : return False
            elif(rem == 2 or rem == 3):
                return False
            
            n//=4
        return True