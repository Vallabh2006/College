/*
SELECT productname, categoryname
FROM products AS p
INNER JOIN product_categories AS pc
ON p.category_id = pc.category_id
ORDER BY categoryname;
*/



/*
SELECT name, SUM(quantity) AS total_items
FROM customers AS c
INNER JOIN orders AS o
ON c.customer_id = o.customer_id
INNER JOIN order_items AS oi
ON o.order_id = oi.order_id
GROUP BY name
ORDER BY total_items DESC;
*/



/*
SELECT DISTINCT name
FROM customers AS c
INNER JOIN orders AS o
ON c.customer_id = o.customer_id
INNER JOIN order_items AS oi
ON o.order_id = oi.order_id
INNER JOIN inventories AS i
ON oi.product_id = i.product_id
INNER JOIN warehouses AS w
ON i.warehouse_id = w.warehouse_id
INNER JOIN locations AS l
ON w.location_id = l.location_id
WHERE warehousename = 'Delhi Warehouse';
*/



/*
SELECT o.order_id, p.productname, oi.unit_price
FROM orders o
JOIN order_items oi
    ON o.order_id = oi.order_id
JOIN products p
    ON oi.product_id = p.product_id
WHERE oi.unit_price = (
    SELECT MAX(unit_price)
    FROM order_items
    WHERE order_id = oi.order_id
)
ORDER BY oi.unit_price DESC;
*/



/*-
SELECT warehousename, SUM(quantity) AS Product_sold
FROM inventories AS i
INNER JOIN warehouses AS w
ON i.warehouse_id = w.warehouse_id
INNER JOIN locations AS l
ON w.location_id = l.location_id
WHERE country_id = 'IN'
GROUP BY warehousename
ORDER BY warehousename;
*/