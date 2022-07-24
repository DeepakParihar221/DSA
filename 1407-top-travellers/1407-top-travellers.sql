# Write your MySQL query statement below
select name, if(sum(distance) is NULL, 0, sum(distance))  AS travelled_distance
from Users left join Rides 
on Users.id = Rides.user_id
group by Rides.user_id
order by travelled_distance desc , name;