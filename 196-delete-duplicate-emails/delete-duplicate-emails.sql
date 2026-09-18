-- Write your PostgreSQL query statement belo
delete from person 
where id not in(
    select min(id)
    from person
    group by email
)