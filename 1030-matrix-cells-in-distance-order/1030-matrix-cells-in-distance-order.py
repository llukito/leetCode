class Solution:
    def allCellsDistOrder(self, rows: int, cols: int, rCenter: int, cCenter: int) -> List[List[int]]:
        pq = []
        for r in range(rows):
            for c in range(cols):
                heapq.heappush(pq, (abs(r-rCenter)+abs(c-cCenter), [r,c]))
        res = []
        for r in range(rows):
            for c in range(cols):
                priority, coords = heapq.heappop(pq)
                res.append(coords)
        return res