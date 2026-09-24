/*
CREATE TABLE warehouse1 LIKE warehouses;

SELECT * FROM warehouse1;
*/



/*
INSERT INTO warehouse1 SELECT * FROM warehouses;

SELECT * FROM warehouse1;
*/



/*
CREATE TABLE employee_m
AS SELECT employee_id, CONCAT(firstname, ' ', lastname)
AS full_name FROM employees;

ALTER TABLE employee_m
MODIFY full_name VARCHAR(511) NOT NULL;

SELECT * FROM employee_m
*/
