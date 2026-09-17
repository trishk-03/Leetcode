-- Write your PostgreSQL query statement below
Select e.name as Employee
from Employee as e
Join Employee as m 
on e.managerId = m.id
where e.salary > m.salary