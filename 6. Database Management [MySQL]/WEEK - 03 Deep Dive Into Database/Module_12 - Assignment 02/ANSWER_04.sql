USE hr;
SELECT DISTINCT salary as Second_Highest_Salary
FROM employees
ORDER BY salary DESC
LIMIT 1 OFFSET 1;
