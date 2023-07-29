DROP DATABASE IF EXISTS phitron;
CREATE DATABASE phitron;
USE phitron;
CREATE TABLE person(
	id INT, 
    email VARCHAR(30)
);

INSERT INTO person(id, email)
VALUES (1, "john@example.com"),
		(2, "bob@example.com"),
        (3, "john@example.com");

SET sql_safe_updates = 0;
SELECT email FROM person;

CREATE TABLE Temp_Person(
SELECT MIN(id) AS id, email
FROM person
GROUP BY email
);

TRUNCATE TABLE person;

INSERT INTO person(id, email)
SELECT id, email FROM Temp_Person;

DROP TABLE Temp_Person;
SET sql_safe_updates = 1;
SELECT id, email FROM person;
