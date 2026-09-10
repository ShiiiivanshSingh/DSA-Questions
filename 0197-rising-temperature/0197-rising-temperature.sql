# Write your MySQL query statement below
select w1.id 
from Weather as w1
join Weather as w2 ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
where w2.temperature <w1.temperature