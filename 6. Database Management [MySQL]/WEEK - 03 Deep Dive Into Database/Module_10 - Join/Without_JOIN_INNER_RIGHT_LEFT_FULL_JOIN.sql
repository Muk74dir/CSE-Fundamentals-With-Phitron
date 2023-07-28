#<----- WITHOUT JOIN BY ALTERNATIVE ------->

SELECT employees.employee_id, employees.first_name, departments.department_name 
FROM employees, departments
WHERE employees.department_id = departments.department_id;

#OR, 

SELECT E.employee_id, E.first_name, D.department_name 
FROM employees AS E, departments D
WHERE E.department_id = D.department_id;


#<----- WITH JOIN METHOD BY USING ------>
SELECT E.employee_id, E.first_name, D.department_name
FROM employees AS E JOIN departments AS D USING (department_id);


#<----- WITH JOIN METHOD BY ON ------>
SELECT E.employee_id, E.first_name, D.department_name
FROM employees AS E JOIN departments AS D 
ON (E.department_id = D.department_id);



#<----- SELF JOIN ------>

SELECT E.first_name, M.first_name
FROM employees AS E JOIN employees AS M
USING (employee_id);

SELECT employee_id, first_name, manager_id FROM employees;

#<----- INNER JOIN ------>
#<----- LEFT JOIN ------>
#<----- RIGHT JOIN ------>
#<----- FULL JOIN ------>

