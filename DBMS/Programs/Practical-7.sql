/*
SELECT CURDATE() AS Date;
*/



/*
SELECT productname,
ROUND(listprice * 1.15) AS "New Price"
FROM products;
*/



/*
SELECT UPPER(firstname) AS name,
LENGTH(firstname) AS length FROM employees
WHERE firstname LIKE 'J%'
    OR firstname LIKE 'A%'
    OR firstname LIKE 'M%';
*/



/*
SELECT firstname,
TIMESTAMPDIFF(YEAR, hiredate, CURDATE()) AS years
FROM employees;
*/



/*
SELECT jobtitle,
COUNT(*) AS total_employees
FROM employees
GROUP BY jobtitle;
*/