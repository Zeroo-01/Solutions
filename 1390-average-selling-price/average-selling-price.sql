# Write your MySQL query statement below
select p.product_id , round(ifnull(sum(p.price*u.units),0)/ifnull(sum(u.units),1),2) as average_price from prices as p left join unitssold as u
on u.product_id=p.product_id and u.purchase_date  between p.start_date and p.end_date group by p.product_id;