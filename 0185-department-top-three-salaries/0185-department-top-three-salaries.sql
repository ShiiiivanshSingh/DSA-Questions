# Write your MySQL query statement below
select Department, Employee, Salary from (
    select 
        d.name as Department, e.name as Employee, e.salary as Salary,
        DENSE_RANK() over (
            PARTITION BY d.name 
            order by salary 
            desc
        ) as raank
    from Employee e
    join Department d
    on e.departmentId = d.Id
)

as raank_table
where  raank <=3