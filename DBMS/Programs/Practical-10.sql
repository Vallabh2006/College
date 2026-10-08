/*
DECLARE
    v_category_name VARCHAR(255) := 'Smart Devices';
BEGIN
    INSERT INTO product_categories (categoryname) 
    VALUES (v_category_name);
END;
/

SELECT * FROM product_categories;
*/



/*
DECLARE
    v_price NUMBER;
BEGIN
    SELECT listprice INTO v_price 
    FROM products 
    WHERE product_id = 1;

    IF v_price > 50000 THEN
        UPDATE products 
        SET listprice = listprice - 2000 
        WHERE product_id = 1;
    ELSE
        UPDATE products 
        SET listprice = listprice + 1000 
        WHERE product_id = 1;
    END IF;
END;
/

SELECT product_id, productname, listprice FROM products WHERE product_id = 1;
*/



/*
DECLARE
    CURSOR c_customers IS
        SELECT name, creditlimit 
        FROM customers 
        ORDER BY creditlimit DESC;
    v_name VARCHAR(255);
    v_credit INT;
    i NUMBER := 1;
BEGIN
    OPEN c_customers;
    LOOP
        FETCH c_customers INTO v_name, v_credit;
        EXIT WHEN c_customers%NOTFOUND OR i > 5;
        
        DBMS_OUTPUT.PUT_LINE(v_name || ' : ' || v_credit);
        i := i + 1;
    END LOOP;
    CLOSE c_customers;
END;
/
*/
