/*
CREATE TABLE regions (
    region_id INT(11) PRIMARY KEY AUTO_INCREMENT,
    regionname VARCHAR(50) DEFAULT NULL
);

INSERT INTO regions (regionname)
VALUES
('North'),
('South'),
('East'),
('West'),
('Central');

SELECT * FROM regions;
*/



/*
CREATE TABLE countries (
    country_id CHAR(2) PRIMARY KEY,
    countryname VARCHAR(40) NOT NULL,
    region_id INT(11),
    FOREIGN KEY (region_id) REFERENCES regions(region_id)
);

INSERT INTO countries (country_id, countryname, region_id)
VALUES
('CN', 'China', 1),
('LK', 'Sri Lanka', 2),
('BD', 'Bangladesh', 3),
('PK', 'Pakistan', 4),
('IN', 'India', 5);

SELECT * FROM countries;
*/



/*
CREATE TABLE locations (
    location_id INT(11) PRIMARY KEY AUTO_INCREMENT,
    address VARCHAR(255) NOT NULL,
    postalcode VARCHAR(20) DEFAULT NULL,
    city VARCHAR(50) DEFAULT NULL,
    state VARCHAR(50) DEFAULT NULL,
    country_id CHAR(2),
    FOREIGN KEY (country_id) REFERENCES countries(country_id)
);

INSERT INTO locations (address, postalcode, city, state, country_id)
VALUES
('No. 1 Changan Avenue', '100006', 'Beijing', 'Beijing', 'CN'),
('12 Galle Road', '00300', 'Colombo', 'Western', 'LK'),
('25 Motijheel Road', '1000', 'Dhaka', 'Dhaka', 'BD'),
('45 Constitution Avenue', '44000', 'Islamabad', 'Islamabad Capital Territory', 'PK'),
('10 Rajpath', '110001', 'New Delhi', 'Delhi', 'IN');

SELECT * FROM locations;
*/



/*
CREATE TABLE warehouses (
    warehouse_id INT(11) PRIMARY KEY AUTO_INCREMENT,
    warehousename VARCHAR(255) DEFAULT NULL,
    location_id INT(11),
    FOREIGN KEY (location_id) REFERENCES locations(location_id)
);

INSERT INTO warehouses (warehousename, location_id)
VALUES
('Beijing Warehouse', 1),
('Colombo Warehouse', 2),
('Dhaka Warehouse', 3),
('Islamabad Warehouse', 4),
('Delhi Warehouse', 5);

SELECT * FROM warehouses;
*/



/*
CREATE TABLE employees (
    employee_id INT(11) PRIMARY KEY AUTO_INCREMENT,
    firstname VARCHAR(255) NOT NULL,
    lastname VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    phone VARCHAR(50) NOT NULL,
    hiredate DATE NOT NULL,
    manager_id INT(11) DEFAULT NULL,
    jobtitle VARCHAR(255) NOT NULL,
    FOREIGN KEY (manager_id) REFERENCES employees(employee_id)
);

INSERT INTO employees (firstname, lastname, email, phone, hiredate, manager_id, jobtitle)
VALUES
('John', 'Smith', 'john.smith@example.com', '9876543210', '2022-01-15', NULL, 'General Manager'),
('Alice', 'Johnson', 'alice.johnson@example.com', '9876543211', '2022-03-10', 1, 'Sales Executive'),
('Bob', 'Williams', 'bob.williams@example.com', '9876543212', '2022-05-20', 1, 'Warehouse Supervisor'),
('Carol', 'Brown', 'carol.brown@example.com', '9876543213', '2023-01-12', 1, 'HR Executive'),
('David', 'Miller', 'david.miller@example.com', '9876543214', '2023-07-08', 2, 'Sales Associate');

SELECT * FROM employees;
*/



/*
CREATE TABLE product_categories (
    category_id INT(11) PRIMARY KEY AUTO_INCREMENT,
    categoryname VARCHAR(255) NOT NULL
);

INSERT INTO product_categories (categoryname)
VALUES
('Electronics'),
('Furniture'),
('Clothing'),
('Groceries'),
('Sports Equipment');

SELECT * FROM product_categories;
*/



/*
CREATE TABLE products (
    product_id INT(11) PRIMARY KEY AUTO_INCREMENT,
    productname VARCHAR(255) NOT NULL,
    description VARCHAR(2000) DEFAULT NULL,
    standardcost INT(11) DEFAULT NULL,
    listprice INT(11) DEFAULT NULL,
    category_id INT(11) NOT NULL,
    FOREIGN KEY (category_id) REFERENCES product_categories(category_id)
);

INSERT INTO products (productname, description, standardcost, listprice, category_id)
VALUES
('Laptop', '15-inch business laptop', 45000, 55000, 1),
('Office Chair', 'Ergonomic office chair', 5000, 7000, 2),
('T-Shirt', '100% cotton round-neck T-shirt', 300, 500, 3),
('Rice Bag', '25 kg premium basmati rice', 1200, 1500, 4),
('Football', 'FIFA standard size 5 football', 700, 1000, 5);

SELECT * FROM products;
*/



/*
CREATE TABLE customers (
    customer_id INT(11) PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    address VARCHAR(255) DEFAULT NULL,
    website VARCHAR(255) DEFAULT NULL,
    creditlimit INT(11) DEFAULT NULL
);

INSERT INTO customers (name, address, website, creditlimit)
VALUES
('ABC Traders', 'Mumbai, India', 'www.abctraders.com', 100000),
('Global Electronics', 'Delhi, India', 'www.globalelectronics.com', 250000),
('Prime Furniture', 'Bengaluru, India', 'www.primefurniture.com', 150000),
('Fresh Mart', 'Chennai, India', 'www.freshmart.com', 80000),
('SportZone', 'Hyderabad, India', 'www.sportzone.com', 120000);

SELECT * FROM customers;
*/



/*
CREATE TABLE orders (
    order_id INT(11) PRIMARY KEY AUTO_INCREMENT,
    status VARCHAR(20) NOT NULL,
    customer_id INT(11) DEFAULT NULL,
    salesman_id INT(11) DEFAULT NULL,
    order_date DATE NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id),
    FOREIGN KEY (salesman_id) REFERENCES employees(employee_id)
);

INSERT INTO orders (status, customer_id, salesman_id, order_date)
VALUES
('Pending', 1, 2, '2024-01-10'),
('Shipped', 2, 2, '2024-01-12'),
('Delivered', 3, 3, '2024-01-15'),
('Pending', 4, 4, '2024-01-18'),
('Cancelled', 5, 5, '2024-01-20');

SELECT * FROM orders;
*/



/*
CREATE TABLE order_items (
    order_id INT(11) NOT NULL,
    item_id INT(11) NOT NULL,
    product_id INT(11) NOT NULL,
    quantity INT(11) NOT NULL,
    unit_price INT(11) NOT NULL,
    PRIMARY KEY (order_id, item_id),
    FOREIGN KEY (order_id) REFERENCES orders(order_id),
    FOREIGN KEY (product_id) REFERENCES products(product_id)
);

INSERT INTO order_items (order_id, item_id, product_id, quantity, unit_price)
VALUES
(1, 1, 1, 2, 55000),
(2, 1, 2, 5, 7000),
(3, 1, 3, 10, 500),
(4, 1, 4, 3, 1500),
(5, 1, 5, 4, 1000);

SELECT * FROM order_items;
*/



/*
CREATE TABLE inventories (
    product_id INT(11) NOT NULL,
    warehouse_id INT(11) NOT NULL,
    quantity INT(11) NOT NULL,
    PRIMARY KEY (product_id, warehouse_id),
    FOREIGN KEY (product_id) REFERENCES products(product_id),
    FOREIGN KEY (warehouse_id) REFERENCES warehouses(warehouse_id)
);

INSERT INTO inventories (product_id, warehouse_id, quantity)
VALUES
(1, 1, 100),
(2, 2, 75),
(3, 3, 200),
(4, 4, 150),
(5, 5, 80);

SELECT * FROM inventories;
*/
