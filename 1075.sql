SELECT p.project_id, ROUND(AVG(CAST(e.experience_years AS DECIMAL(10,2))), 2) as average_years
FROM Project as p
JOIN Employee as e
ON p.employee_id = e.employee_id
GROUP BY p.project_id
