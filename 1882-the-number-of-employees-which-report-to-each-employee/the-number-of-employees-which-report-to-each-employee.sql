select e.employee_id,e.name,count(r.employee_id) as reports_count,round(avg(r.age)) as average_age 
from employees as e 
inner join 
employees as r on e.employee_id=r.reports_to
group by employee_id
order by employee_id 