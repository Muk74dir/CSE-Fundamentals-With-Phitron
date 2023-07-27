USE hr;
SELECT job_id, COUNT(*)
FROM employees
GROUP BY job_id
HAVING COUNT(*) > 1;