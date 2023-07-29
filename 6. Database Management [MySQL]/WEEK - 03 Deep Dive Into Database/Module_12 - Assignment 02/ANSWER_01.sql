DROP DATABASE IF EXISTS phitron;
CREATE DATABASE phitron;
USE phitron;

CREATE TABLE customers(
	id INT PRIMARY KEY,
    _name VARCHAR(30)
);

CREATE TABLE orders(
	id INT, 
    customer_id INT
    -- FOREIGN KEY (customer_id)
-- 		REFERENCES customers(id)
--         ON DELETE CASCADE
);

INSERT INTO customers(id, _name)
VALUES (101, "Muktadir"),
		(102, "Raju"),
        (103, "Foysal"),
        (104, "Rahim"),
        (105, "KARIM");
        
SELECT * FROM customers;

INSERT INTO orders(id, customer_id)
VALUES (1, 101),
		(2, 103),
        (3, 105),
        (4, 108),
        (5, 110);
        
SELECT C._name
FROM customers AS C
LEFT JOIN
orders AS O
ON (C.id = O.customer_id)
WHERE O.customer_id IS NULL;
