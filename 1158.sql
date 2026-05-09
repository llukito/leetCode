/* Write your T-SQL query statement below */
;WITH o as (
    SELECT * FROM Orders
    WHERE YEAR(order_date) = 2019
)

SELECT u.user_id as buyer_id, u.join_date, COUNT(o.buyer_id) as orders_in_2019
FROM Users as u
LEFT JOIN o ON u.user_id = o.buyer_id
GROUP BY u.user_id, u.join_date
