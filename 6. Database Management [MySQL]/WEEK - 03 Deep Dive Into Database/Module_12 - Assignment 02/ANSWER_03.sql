DROP DATABASE IF EXISTS phitron;
CREATE DATABASE phitron;
USE phitron;

CREATE TABLE weather(
	id INT PRIMARY KEY,
    recordDate DATE,
    temperature INT
);

INSERT INTO weather (id, recordDate, temperature)
VALUES (1, "2015-01-01", 10),
		(2, "2015-01-02", 25),
        (3, "2015-01-03", 20),
        (4, "2015-01-04", 30);
        
SELECT * FROM weather;

SELECT W1.id
FROM weather AS W1 
JOIN weather AS W2 
ON (W1.recordDate = DATE_ADD(W2.recordDate, INTERVAL 1 DAY) )
WHERE (W1.temperature > W2.temperature);