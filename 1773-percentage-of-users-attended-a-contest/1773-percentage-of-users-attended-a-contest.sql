# Write your MySQL query statement below
select 
    contest_id , ROUND(count(distinct r.user_id) * 100 / ( select count(*) from users),2 ) as percentage 
    from Users
    join Register as r
    group by contest_id
    order by percentage DESC, contest_id;