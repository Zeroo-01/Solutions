# Write your MySQL query statement below
select r.contest_id, round(100*count(r.user_id)/(select count(*) from users),2) as percentage 
from register  as r 
 group by r.contest_id order by percentage desc,contest_id asc;