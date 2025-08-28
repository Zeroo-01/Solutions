# Write your MySQL query statement below
select distinct p.email as Email from person as p left join person as pp 
on p.email=pp.email where p.id!=pp.id;