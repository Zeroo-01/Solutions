# Write your MySQL query statement below
-- select account_id,income ,
-- case
-- when income<20000 then 'Low Salary'
-- when income>50000 then 'High Salary'
-- else 'Average Salary'
-- end as category
-- from accounts 

select 'Low Salary' as category, coalesce(count(account_id) ,0) as accounts_count
from accounts where income <20000

union all

select 'Average Salary' as category, coalesce(count(account_id) ,0) as accounts_count
from accounts where income >=20000 and income<=50000

union all

select 'High Salary' as category, coalesce(count(account_id) ,0) as accounts_count
from accounts where income >50000

