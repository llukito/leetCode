;WITH t as (SELECT *,
MIN(event_date) OVER(PARTITION BY player_id) as firstLogin
FROM Activity),
m as (
    SELECT *,
    CASE WHEN DATEDIFF(day, firstLogin, event_date) = 1 THEN 1 ELSE 0 END as valid
    FROM t
), s as (
    SELECT COUNT(DISTINCT player_id) as allPlayers, SUM(valid) as good
    FROM m
)

SELECT ROUND(good/CAST(allPlayers as FLOAT), 2) as fraction
FROM s
