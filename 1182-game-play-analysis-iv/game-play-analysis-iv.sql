# Write your MySQL query statement below
with cte_firstlogin as
(
    select player_id, min(event_date) as firstlogin 
    from activity
    group by player_id
),
cte_second as
(
    select distinct a.player_id
    from activity as a inner join cte_firstlogin as cte on a.player_id = cte.player_id and 
    datediff(a.event_date,cte.firstlogin)=1
    
)
select round(count(cts.player_id)/count(cte.player_id),2) as fraction from
cte_firstlogin as cte 
left join
cte_second as cts 
on cte.player_id=cts.player_id;
