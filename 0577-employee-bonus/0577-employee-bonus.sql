# Write your MySQL query statement below
select a.name , b.bonus
from Employee a 
left join Bonus b
on a.empId = B.empId
where b.bonus < 1000 OR b.bonus is null
