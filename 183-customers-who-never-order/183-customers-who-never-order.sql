# Write your MySQL query statement below
select customers.name as Customers from customers where id not in (select customerId from orders);