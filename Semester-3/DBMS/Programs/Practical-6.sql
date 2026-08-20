/* (Optional)
INSERT INTO countries (country_id, countryname, region_id)
VALUES
('JP', 'Japan', 1),
('KR', 'South Korea', 1),
('TH', 'Thailand', 2),
('MY', 'Malaysia', 2),
('NP', 'Nepal', 3),
('BT', 'Bhutan', 3),
('AF', 'Afghanistan', 4),
('IR', 'Iran', 4),
('AE', 'United Arab Emirates', 5),
('SA', 'Saudi Arabia', 5);

INSERT INTO products
(product_id, productname, description, standardcost, listprice, category_id)
VALUES
(6, 'Smartphone', '128GB 5G smartphone', 18000, 22000, 1),
(7, 'Wireless Headphones', 'Bluetooth noise-cancelling headphones', 2500, 3500, 1),

(8, 'Study Table', 'Wooden study table with storage drawer', 4000, 5500, 2),
(9, 'Bookshelf', 'Five-shelf wooden bookshelf', 6000, 8000, 2),

(10, 'Jeans', 'Regular fit blue denim jeans', 1200, 1800, 3),
(11, 'Hoodie', 'Cotton hooded sweatshirt', 900, 1400, 3),

(12, 'Cooking Oil', '1 litre refined sunflower cooking oil', 120, 160, 4),
(13, 'Pasta', '500 gram premium durum wheat pasta', 80, 120, 4),

(14, 'Cricket Bat', 'English willow cricket bat', 3000, 4500, 5),
(15, 'Basketball', 'Official size indoor basketball', 1000, 1600, 5);

*/



/*
SELECT * FROM employees ORDER BY hiredate;
*/



/*
SELECT * FROM products GROUP BY listprice DESC, category_id;
*/



/*
SELECT countryname,
    CASE
        WHEN region_id = 1 THEN 'North'
        WHEN region_id = 2 THEN 'South'
        WHEN region_id = 5 THEN 'Central'
    END AS direction
FROM countries
WHERE region_id IN (1, 2, 5)
ORDER BY FIELD(region_id, 1, 2, 5);
*/



/*
SELECT productname, category_id
FROM products
WHERE category_id IN (3, 1, 5)
ORDER BY FIELD(category_id, 3, 1, 5);
*/



/*
SELECT 
    CONCAT('P', product_id) AS id,
    productname,
    category_id
FROM products
WHERE product_id IN (1, 2, 3, 5, 6, 7, 9)
ORDER BY product_id;  
*/



/*
SELECT productname, category_id, listprice AS min_price
FROM products
WHERE (category_id, listprice) IN (
    SELECT category_id, MIN(listprice)
    FROM products
    GROUP BY category_id
)
ORDER BY category_id;
*/