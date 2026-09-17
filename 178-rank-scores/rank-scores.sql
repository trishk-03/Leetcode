-- Write your PostgreSQL query statement below
select score, DENSE_RANK() over (Order by score desc) as rank
from Scores
order by score desc;