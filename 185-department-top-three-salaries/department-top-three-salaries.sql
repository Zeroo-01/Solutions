# Write your MySQL query statement below

select DEPARTMENT,Employee,salary
from (select c.id,c.name as 'Employee',c.salary,c.departmentid,d.name as 'Department',
dense_rank() over(partition by departmentid order by salary desc) ranks 
from employee as c join department as d
on c.departmentid=d.id)t
where ranks<=3
