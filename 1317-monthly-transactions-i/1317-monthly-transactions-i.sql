# Write your MySQL query statement below
select 
    DATE_FORMAT(trans_date , '%Y-%m') as month,
    country,
    count(*)  as trans_count,
   SUM(state = 'approved') as approved_count ,
    SUM(amount) as trans_total_amount,
    SUM(case when state = 'approved' then amount else 0 end ) as approved_total_amount 
from Transactions
group by DATE_FORMAT(trans_date , '%Y-%m') , country 
order by month , country;