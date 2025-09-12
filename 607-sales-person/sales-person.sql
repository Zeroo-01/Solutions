# Write your MySQL query statement below
select name from salesperson where name not in (SELECT s.name from orders as o join salesperson s on s.sales_id=o.sales_id
join company as c on o.com_id=c.com_id where c.name="RED");

