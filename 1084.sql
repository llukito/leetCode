;With e as(SELECT p.product_id, p.product_name,
CASE
WHEN s.sale_date BETWEEN '2019-01-01' AND '2019-03-31' THEN 0
ELSE 1
END as dt
FROM Product as p
JOIN Sales as s ON p.product_id = s.product_id)

SELECT e.product_id, e.product_name
FROM e
GROUP BY e.product_id, e.product_name
HAVING SUM(e.dt) = 0
