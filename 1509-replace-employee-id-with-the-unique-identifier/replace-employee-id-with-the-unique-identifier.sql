# Write your MySQL query statement below
select e.unique_id,ee.name from employees as ee left join employeeUNI as e on ee.id=e.id;