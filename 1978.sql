SELECT e.employee_id FROM Employees as e
WHERE e.salary < 30000 and e.manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id
