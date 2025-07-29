# Write your MySQL query statement below
select visited_on,sum(amount) over(order by visited_on rows between 6 preceding and current row) as amount,
round(sum(amount) over(order by visited_on rows between 6 preceding and current row)/7,2) as average_amount
from (select visited_on , sum(amount) as amount from customer group by visited_on) 
as t   order by visited_on limit 6,9999