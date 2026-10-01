/*
START TRANSACTION;

UPDATE products
SET listprice = listprice * 1.05
WHERE category_id = 1;

UPDATE products
SET description = 'Ergonomic high-back office chair with lumbar support'
WHERE product_id = 2;

COMMIT;
*/



/*
START TRANSACTION;

DELETE FROM products
WHERE product_id = 10;

SELECT * FROM products WHERE product_id = 10;

ROLLBACK;

SELECT * FROM products WHERE product_id = 10;
*/



/*
CREATE OR REPLACE VIEW product_price_view AS
SELECT
    product_id,
    productname,
    listprice
FROM products;

SELECT * FROM product_price_view;
*/



/*
DROP VIEW IF EXISTS product_price_view;

SELECT * FROM product_price_view;

CREATE VIEW product_price_view AS
SELECT
    product_id,
    productname,
    listprice
FROM products;
*/



/*
SELECT
    c.categoryname,
    MIN(p.listprice) AS min_price
FROM products p
JOIN product_categories c ON p.category_id = c.category_id
GROUP BY c.categoryname;
*/
