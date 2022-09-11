select name as Customers from customers
where id not in (select orders.customerId from orders);
