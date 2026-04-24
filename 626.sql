WITH t as (SELECT id, 
CASE
WHEN (id%2 = 1 AND id = (SELECT Count(*) FROM Seat)) Then id
WHEN id%2 = 1 THEN id+1
WHEN id%2 = 0 THEN id-1
END AS tempId
FROM Seat)

SELECT t.id, s.student
FROM t
JOIN Seat as s ON s.id = t.tempId
ORDER By t.id
