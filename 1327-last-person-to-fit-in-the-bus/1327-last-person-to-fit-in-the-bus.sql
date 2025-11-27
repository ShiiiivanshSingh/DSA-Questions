# Write your MySQL query statement below
select person_name 
from (select
    person_name,
    person_id ,
    SUM(weight) over(order by turn ) as temp
 from Queue
)  q

where temp<=1000
order by temp desc
limit 1;