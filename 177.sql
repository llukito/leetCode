CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT
CASE
WHEN N IN
(SELECT s FROM (SELECT id, salary, DENSE_RANK() over(ORDER BY salary DESC) as s
FROM Employee) as t)
THEN (SELECT MAX(salary) FROM 
(SELECT id, salary, DENSE_RANK() over(ORDER BY salary DESC) as s
FROM Employee) as t WHERE s = N)
ELSE NULL 
END as SecondHighestSalary

  );
END
