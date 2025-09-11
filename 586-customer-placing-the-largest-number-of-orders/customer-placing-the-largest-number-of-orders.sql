# Write your MySQL query statement below
SELECT customer_number from (select customer_number ,count(*) as total from orders group by customer_number)t order by total desc limit 1;