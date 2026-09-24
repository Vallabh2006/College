/*
SELECT * FROM employees
WHERE lastname LIKE '%ada%';
*/



/*
SELECT * FROM employees
WHERE lastname LIKE 'Jan%' OR lastname LIKE '%na';
*/



/*
SELECT * FROM employees
WHERE lastname LIKE 'D_a__';
*/



/*
SELECT name,
  CASE
    WHEN creditlimit > 2500 THEN 'high' ELSE 'low'
  END AS remark
FROM customers;
*/



/*
SELECT * FROM products
ORDER BY product_id LIMIT 10;   

SELECT * FROM products
ORDER BY product_id LIMIT 1 OFFSET 3;
*/