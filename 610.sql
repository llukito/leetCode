SELECT *, 
CASE
WHEN x > 0 AND y > 0 AND z > 0 AND 
(x + y > z AND y + z > x AND z + x > y)
THEN 'Yes'
ELSE 'No'
END as triangle
FROM Triangle
