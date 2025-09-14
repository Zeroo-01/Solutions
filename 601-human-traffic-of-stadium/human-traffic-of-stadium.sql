select id,visit_date,people from
(select *,
lead(people) over(order by visit_date) as nxt1,
lead(people,2) over(order by visit_date) as nxt2,
lag(people) over(order by visit_date) as prev1,
lag(people,2)over(order by visit_date) as prev2
from stadium)t
where people>=100 and ((nxt1>=100 and nxt2>=100) or(prev2>=100 and prev1>=100) or (nxt1>=100 and prev1>=100))
order by visit_date

