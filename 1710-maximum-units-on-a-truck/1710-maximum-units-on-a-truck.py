class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: (x[1], x[0]))
        idx = len(boxTypes)-1
        res = 0 
        while truckSize>0 and idx >=0:
            num = boxTypes[idx][0]
            per = boxTypes[idx][1]
            res+= per*(min(truckSize, num))
            idx-=1
            truckSize-=num
        return res