Select DISTINCT p1.email
FROM Person as p1
JOIN Person as p2 
on p1.email = p2.email AND p1.id != p2.id
