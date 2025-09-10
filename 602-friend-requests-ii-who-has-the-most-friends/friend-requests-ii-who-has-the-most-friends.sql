# Write your MySQL query statement below
select requester_id as id , count(*) as num
from(
    select requester_id from requestaccepted
    union all
    select accepter_id from requestaccepted
)t
group by id order by num desc limit 1 ;
