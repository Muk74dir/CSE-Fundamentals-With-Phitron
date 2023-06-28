CREATE DATABASE PHITRON;
USE PHITRON;

CREATE TABLE STUDENT (
	Roll INT,
	_Name VARCHAR(30), 
	ContactNo CHAR(11),
	Email VARCHAR(30)
);

INSERT INTO Student(Roll, _Name, ContactNo, Email)
VALUES (101, "Rahim", "01871727699", "rahim@gmail.com");

INSERT INTO Student(Roll, _Name, Email)
VALUES (102, "Ayush", "ayush@gmail.com");

SELECT * FROM STUDENT;