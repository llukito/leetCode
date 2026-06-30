SELECT contest_id,
ROUND(100 * COUNT(user_id)/ CAST ((SELECT COUNT(user_id) FROM Users) as FLOAT), 2) as percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC
