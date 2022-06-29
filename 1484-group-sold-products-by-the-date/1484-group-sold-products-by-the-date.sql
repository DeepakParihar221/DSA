# Write your MySQL query statement below
select sub.sell_date,  count(sub.sell_date) as num_sold, 
GROUP_CONCAT(sub.product order by  sub.product SEPARATOR ',') as products 
from(select distinct sell_date, product from Activities)sub 
group by sell_date 
order by sell_date;

# select distinct sell_date, product from Activities