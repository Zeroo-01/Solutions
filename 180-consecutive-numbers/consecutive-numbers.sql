# Write your MySQL query statement below
select distinct num as ConsecutiveNums from(
select * , lead(num,1) over(order by id) as next, lead(num,2) over(order by id) as two from logs)t
where num=next and num=two