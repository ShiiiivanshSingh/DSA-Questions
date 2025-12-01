# Write your MySQL query statement below
select sell_date,
    count(distinct product) as num_sold,
    CONCAT( GROUP_CONCAT(DISTINCT product ORDER BY product)) AS products
from Activities
GROUP BY 
    sell_date
ORDER BY 
    sell_date;