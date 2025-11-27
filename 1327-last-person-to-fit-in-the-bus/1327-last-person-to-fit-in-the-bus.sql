# Write your MySQL query statement below
select person_name 
from (select
    person_name,
    person_id ,
    SUM(weight) over(order by turn ) as cuurent
 from Queue
)  q

where cuurent<=1000
order by cuurent desc
limit 1;