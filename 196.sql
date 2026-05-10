;WITH s as(
    SELECT email,
    ROW_NUMBER() OVER (PARTITION BY email ORDER BY id) AS row_num
    FROM Person
)

DELETE FROM s 
WHERE row_num != 1
