# Write your MySQL query statement below
select product_id, year as first_year, quantity,price from(
select *, 
rank() over(partition by product_id order by year) as ranks from sales)
as ranked 
where ranks=1;