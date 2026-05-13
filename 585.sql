;WITH e as (SELECT i1.pid, i1.tiv_2015, i1.tiv_2016, i1.lat, i1.lon
FROM Insurance as i1
WHERE i1.tiv_2015 IN (SELECT i2.tiv_2015 FROM Insurance as i2 WHERE i2.pid != i1.pid) AND CAST(i1.lat as VARCHAR(20)) + '|' + CAST(i1.lon as VARCHAR(20)) NOT IN (SELECT CAST(i2.lat as VARCHAR(20)) + '|' + CAST(i2.lon as VARCHAR(20)) FROM Insurance as i2 WHERE i2.pid != i1.pid)
)

SELECT ROUND(SUM(tiv_2016), 2) as tiv_2016
FROM e
