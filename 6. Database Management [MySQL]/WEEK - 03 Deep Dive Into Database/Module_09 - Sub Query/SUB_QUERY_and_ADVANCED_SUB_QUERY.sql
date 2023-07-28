-- <----------# SUB_QUERY BASICS #---------->

use hr;
SELECT first_name
FROM employees
WHERE employee_id = 107;

SELECT first_name, salary
FROM employees
WHERE salary < (
			SELECT salary 
            FROM employees 
            WHERE employee_id = 107
);


-- Included Diana.
SELECT first_name, salary
FROM employees
WHERE salary = (
			SELECT salary 
            FROM employees 
            WHERE employee_id = 107
);

-- Exculded Diana.
SELECT first_name, salary
FROM employees
WHERE employee_id != 107 AND salary = (
			SELECT salary 
            FROM employees 
            WHERE employee_id = 107
);


-- #QUESTION :--> How much salary and Who are those people whom match to Diana's job type?

SELECT first_name, last_name, salary
FROM employees
WHERE job_id = (SELECT job_id
				FROM employees
                WHERE employee_id = 107
);

-- #QUESTION :--> Show the employees name of those people whom 
-- job_id is similar as Diana and greater than Danial's salary

SELECT first_name
FROM employees
WHERE job_id = (SELECT job_id
				FROM employees
                WHERE employee_id = 107)
	AND salary > ( SELECT salary
		FROM employees
        WHERE job_id = 109
);


-- # SubQuery into another SubQuery :--> 

SELECT first_name
FROM employees
WHERE job_id = (SELECT job_id
				FROM employees
                WHERE employee_id = ( SELECT employee_id
									  FROM employees
									  WHERE first_name = "Diana"
									  LIMIT 1)
);


-- <--------# ADVANCED SUB_QUERY #--------->
SELECT first_name, last_name, job_id, salary
FROM employees
WHERE job_id != "IT_PROG" AND salary < ANY (
				SELECT salary 	
                FROM employees 	
                WHERE job_id = "IT_PROG");

-- ADVANCED CO-RELATED SUB_QUERY :-->

SELECT *
FROM employees as e1
WHERE 3 <= ( SELECT COUNT(*) 
			FROM employees as e2 
            WHERE e2.salary < e1.salary ); 


-------# ADVANCED : NOT EXISTS #---::---> 

SELECT first_name, last_name, salary, department_id
FROM employees as E1
WHERE NOT EXISTS ( SELECT * FROM employees as E2 
					WHERE E1.department_id = E2.department_id AND 
                    E2.salary > E1.salary);