# Write your MySQL query statement below
select e.name as 'employee' from employee as e left join employee as ee on
e.managerid=ee.id where e.salary>ee.salary;