
(
SELECT u.name AS results
FROM Users u
JOIN MovieRating m
  ON u.user_id = m.user_id
GROUP BY u.user_id
ORDER BY COUNT(*) DESC, u.name
LIMIT 1
)

union all
(
select k.title as results
from Movies k
join MovieRating m
    on m.movie_id = k.movie_id
where m.created_at  BETWEEN '2020-02-01' AND '2020-02-29'
group by m.movie_id
order by AVG(rating) DESC, k.title
limit 1 );