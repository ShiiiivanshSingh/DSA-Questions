SELECT 'Low Salary' AS category,
       SUM(income < 20000) AS accounts_count
FROM Accounts

UNION ALL

SELECT 'Average Salary',
       SUM(income BETWEEN 20000 AND 50000)
FROM Accounts

UNION ALL

SELECT 'High Salary',
       SUM(income > 50000)
FROM Accounts;



-- # Write your MySQL query statement below
-- select 
--     case when income > 50000 then 'High Salary' 
--     when income >= 20000 and income <=  50000 then 'Average Salary'
--     else 'Low Salary'
--     END as category,
--     CASE WHEN income > 50000 THEN 1 ELSE 0 END AS high_cnt,
--     CASE WHEN income >= 20000 AND income <= 50000 THEN 1 ELSE 0 END AS avg_cnt,
--     CASE WHEN income < 20000 THEN 1 ELSE 0 END AS low_cnt

-- from Accounts

-- union all

-- select 
--     'Total',
--     sum(case when income > 50000 THEN 1 ELSE 0 end),
--     sum(case when income >= 20000 and income <=  50000   THEN 1 ELSE 0 end),
--     sum(case when income < 20000 THEN 1 ELSE 0 end)
--     -- END as category,

-- from Accounts

