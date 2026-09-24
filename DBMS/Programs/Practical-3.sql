/*
ALTER TABLE employee_m
ADD salary INT NOT NULL;

SELECT * FROM employee_m;
*/



/*
ALTER TABLE employee_m
MODIFY salary FLOAT(8,2) NOT NULL;

SELECT * FROM employee_m;
*/



/*
ALTER TABLE employee_m
CHANGE salary salary_e INT NOT NULL;

SELECT * FROM employee_m;
*/



/*
ALTER TABLE employee_m
ADD date_of_joining DATE AFTER full_name;

SELECT * FROM employee_m;
*/



/*
ALTER TABLE employee_m
DROP COLUMN date_of_joining;

RENAME TABLE employee_m TO employee_r;

SELECT * FROM employee_r;
*/



/*
ALTER TABLE employee_r
ADD PRIMARY KEY;

ALTER TABLE employee_r
DROP PRIMARY KEY;

TRUNCATE TABLE employee_r;

SELECT * FROM employee_r;
*/