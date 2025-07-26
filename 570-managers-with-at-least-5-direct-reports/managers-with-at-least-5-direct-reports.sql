# Write your MySQL query statement below
select e.name from employee as e inner join employee as ee on e.id=ee.managerid 
group by e.id having count(*)>=5;