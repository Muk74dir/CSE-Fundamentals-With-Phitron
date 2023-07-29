# ------- FUNCTION --------
SELECT UPPER("THIS IS A PEN") AS UPPERNAME;
SELECT COS(0) AS COSINE;
SELECT COS(90); -- RADIAN VALUE
SELECT COS(90 * PI() / 180); -- RADIAN VALUE
SELECT RADIANS(90);
SELECT CEIL(23.324);
SELECT LOG(10);
SELECT LOG2(10);
SELECT LN(10); 	
SELECT LOG2(2);


USE hr;
# ------- GROUP FUNCTION --------
SELECT MAX(salary)
FROM employees;

SELECT COUNT(*) -- OR, COUNT(employee_id) / Row Count.
FROM employees;

SELECT COUNT(employee_id)
FROM employees;

SELECT SUM(salary)
FROM employees;

SELECT AVG(salary)
FROM employees;

# ---------- GROUP BY FUNCTION -------
SELECT job_id, COUNT(*)
FROM employees
GROUP BY job_id;

SELECT job_id, MAX(salary)
FROM employees
GROUP BY job_id;

SELECT job_id, SUM(salary)
FROM employees
GROUP BY job_id;

SELECT job_id, AVG(salary)
FROM employees
GROUP BY job_id;

