# Write your MySQL query statement below
-- select s.student_id,s.student_name,e.subject_name, count(e.subject_name) as attended_exams from students as s 
-- right join examinations as e on s.student_id=e.student_id group by s.student_id,e.subject_name;

select s.student_id,s.student_name,ss.subject_name, count(e.subject_name) as attended_exams from students as s
cross join subjects as ss
left join examinations as e
on s.student_id=e.student_id and e.subject_name=ss.subject_name group by s.student_id,s.student_name,ss.subject_name 
order by s.student_id,s.student_name;
