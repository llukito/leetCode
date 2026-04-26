SELECT employee_id
FROM Employees
WHERE employee_id NOT IN(SELECT e.employee_id
FROM Employees as e
JOIN Salaries as s ON e.employee_id = s.employee_id)

UNION

SELECT employee_id
FROM Salaries
WHERE employee_id NOT IN(SELECT e.employee_id
FROM Employees as e
JOIN Salaries as s ON e.employee_id = s.employee_id)

ORDER BY employee_id ASC
