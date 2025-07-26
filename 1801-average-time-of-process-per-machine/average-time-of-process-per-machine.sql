# Write your MySQL query statement below
select m.machine_id,round(avg(mm.timestamp-m.timestamp),3) as processing_time from activity as m 
inner join 
activity as mm 
on mm.timestamp>=m.timestamp and m.machine_id=mm.machine_id and m.process_id=mm.process_id and m.activity_type='start' and mm.activity_type='end' group by m.machine_id;