# Write your MySQL query statement below
SELECT customer_number from
orders
group by customer_number
having count(*) =(select count(*) as total from orders group by customer_number order by total desc limit 1);
