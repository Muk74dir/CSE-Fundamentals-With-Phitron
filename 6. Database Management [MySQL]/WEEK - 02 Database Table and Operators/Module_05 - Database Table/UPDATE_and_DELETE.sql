use phitron;
create table student(
	roll int not null unique primary key, 
    _name varchar(30), 
    contact_no char(11) not null,
    email varchar(30)
);

insert into Student(roll, _name, contact_no, email)
values(101, "Rahim", "01932343233", "Musa@gmail.com");

insert into Student(roll, _name, contact_no, email)
values(122, "Karim", "01932343233", "Masdfa@gmail.com");

insert into Student(roll, _name, contact_no, email)
values(123, "Karim", "01932343233", "Masdfa@gmail.com");

set sql_safe_updates = 0;
delete from student
where roll = 101;
set sql_safe_updates = 1;

select *
From student
WHERE roll = 122;