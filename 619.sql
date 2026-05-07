SELECT MAX(num) AS num
FROM (
    SELECT num
    FROM MyNuambers
    GROUP BY num
    HAVING COUNT(num) = 1
) AS singles
