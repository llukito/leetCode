class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        res = 0 
        bottles = 0
        while True :
            if numBottles == 0 and bottles < numExchange : break
            res+=numBottles
            bottles+=numBottles
            n = bottles//numExchange
            numBottles = n
            bottles-=n*numExchange
        return res
