# Write your MySQL query statement below
select  p.product_id, ROUND( 
    COALESCE(SUM(k.units * p.price) / SUM(k.units), 0), 2) as average_price 

from  Prices p
left join UnitsSold k 
on k.product_id = p.product_id

and k.purchase_date between p.start_date and p.end_date    
group by p.product_id 

-- SELECT
