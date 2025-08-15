class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        curr = 0
        allTime = 0.0
        for i in range(len(customers)):
            arrival = customers[i][0]
            cook = customers[i][1]
            currTime = 0
            currTime = max(0,curr-arrival)
            currTime+=cook
            allTime+=currTime
            curr =(max(arrival, curr) + cook)
        return allTime/len(customers)
