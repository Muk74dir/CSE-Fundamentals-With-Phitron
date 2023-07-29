-- ARITHMATIC OPERATORS : 
SELECT 4*3;
SELECT 4+5 FROM countries;

-- LOGICAL OPERATORS : 
SELECT first_name, salary
FROM EMPLOYEES
WHERE salary = 9000;

SELECT first_name, salary
FROM EMPLOYEES
WHERE salary BETWEEN 9000 AND 10000;


-- LOGICAL AND, OR OPERATORS : 
SELECT * 
FROM employees
WHERE first_name = "Steven" OR salary > 22000;


-- IN, NOT IN, LIKE, AS OPERATORS : 
# IN : 
SELECT * 
FROM employees
-- WHERE  jod_id = " " OR job_id = " " OR .... OR .. OR..  
WHERE job_id IN ("AC_ACCOUNT", "AC_MGR", "AD_ASST");

# NOT IN : 
SELECT * 
FROM employees
WHERE job_id NOT IN ("AC_ACCOUNT", "AC_MGR", "AD_ASST");

# LIKE : 
SELECT * 
FROM employees
WHERE first_name LIKE "Sh%";

# AS : 
SELECT first_name as NAME_JADIBOTAI
FROM employees