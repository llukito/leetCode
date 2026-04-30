SELECT DISTINCT e.num as ConsecutiveNums FROM (SELECT id, num, LEAD(num, 1) OVER(ORDER BY id) as n2, LEAD(num, 2) OVER(ORDER BY id) as n3
FROM Logs) as e
WHERE e.num = e.n2 AND e.n2 = e.n3
