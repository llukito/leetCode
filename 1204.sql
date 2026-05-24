;WITH t as (
    SELECT e2.person_name, e2.w,
    MAX(e2.w) OVER() as m
    FROM (SELECT e.person_name,
    SUM(e.weight) OVER(ORDER BY e.turn) as w
    FROM Queue as e) as e2
    WHERE e2.w <= 1000
)

SELECT t.person_name
FROM t
WHERE t.w = t.m
