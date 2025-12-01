select
    P.product_name as product_name,
    SUM(o.unit) as unit    
from
    Products as P
join
    Orders as o
on 
    P.product_id = o.product_id    
where 
    o.order_date between '2020-02-01' AND '2020-02-29'
group by
    P.product_id
having 
    sum(o.unit) >= 100
order by 
    P.product_name

-- if unit>= 100
-- between DATESUB()