/*
DECLARE
    CURSOR c_emp IS
        SELECT firstname, lastname, hiredate 
        FROM employees 
        WHERE EXTRACT(YEAR FROM hiredate) = 2022;
    v_fname VARCHAR(255);
    v_lname VARCHAR(255);
    v_hdate DATE;
BEGIN
    OPEN c_emp;
    LOOP
        FETCH c_emp INTO v_fname, v_lname, v_hdate;
        EXIT WHEN c_emp%NOTFOUND;
        
        DBMS_OUTPUT.PUT_LINE(v_fname || ' ' || v_lname || ' hired on: ' || v_hdate);
    END LOOP;
    CLOSE c_emp;
END;
/
*/



/*
CREATE OR REPLACE PROCEDURE GetTotalOrderValue (
    p_cust_id IN INT,
    p_total_value OUT NUMBER
) AS
BEGIN
    SELECT NVL(SUM(oi.quantity * oi.unit_price), 0)
    INTO p_total_value
    FROM orders o
    JOIN order_items oi ON o.order_id = oi.order_id
    WHERE o.customer_id = p_cust_id;
END;
/

DECLARE
    v_total NUMBER;
BEGIN
    GetTotalOrderValue(1, v_total);
    DBMS_OUTPUT.PUT_LINE('Total Order Value: ' || v_total);
END;
/
*/



/*
DROP TABLE IF EXISTS product_log;

CREATE TABLE product_log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    product_name VARCHAR(255),
    action VARCHAR(50),
    log_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE OR REPLACE TRIGGER trg_after_product_insert
AFTER INSERT ON products
FOR EACH ROW
BEGIN
    INSERT INTO product_log (product_name, action)
    VALUES (:NEW.productname, 'NEW PRODUCT ADDED');
END;
/

INSERT INTO products (productname, description, standardcost, listprice, category_id)
VALUES ('Smart Watch', 'Fitness tracking watch', 2000, 3500, 1);

SELECT * FROM product_log;
*/
