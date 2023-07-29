CREATE DATABASE PHITRON;
USE PHITRON;

DROP TABLE Student;

CREATE TABLE STUDENT (
	Roll INT NOT NULL UNIQUE PRIMARY KEY,
	_Name VARCHAR(30) NOT NULL UNIQUE,
    
    age INT CHECK ( age>= 18 ), 
	CHECK( age>= 18), 
    CONSTRAINT CHECK(age>= 18), 
    CONSTRAINT checker CHECK(age>= 18), 
    
	ContactNo CHAR(11) NOT NULL,
	Email VARCHAR(30), 
    UNIQUE(Email), UNIQUE(ContactNo),
    
    weight INT,
    CONSTRAINT UNIQUE (weight),
    
    Address VARCHAR(50),
    CONSTRAINT unq UNIQUE(Address)
    
);