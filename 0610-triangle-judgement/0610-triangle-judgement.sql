# Write your MySQL query statement below
-- lenth of one sid eis less than sum other 2
SELECT x,y,z,
    CASE WHEN x + y> z AND x+z>y AND y + z > x
    THEN "Yes"
    ELSE "No"
    END
    as triangle
FROM Triangle
