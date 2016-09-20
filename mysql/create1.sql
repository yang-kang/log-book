show databaes;

drop database IF EXISTS shop;

show tables;

create database shop;

use shop;

drop table IF EXISTS client;
drop table IF EXISTS commodity;
drop table IF EXISTS orderf;

create table client(
	id integer not null auto_increment,
	name varchar(15),
	sex varchar(15),
	birthday date,
	tel varchar(20),
	Email varchar(20),
	PRIMARY  KEY(`id`)
);
create table commodity(
	id integer not null auto_increment,
	c_name varchar(15),
	money integer,
	numer integer,
	facturers varchar(15),
	date_time date,
	PRIMARY  KEY(`id`)
);
insert into client(name,sex,birthday,tel,Email) values('zhang','f','1991-01-01','13412345678','1234578@qq.com');
insert into client(name,sex,birthday,tel,Email) values('wang','m','1992-07-01','165623445678','1724578@qq.com');
insert into client(name,sex,birthday,tel,Email) values('li','f','1981-9-01','13412345678','1234578@qq.com');
insert into client(name,sex,birthday,tel,Email) values('liu','m','1995-11-01','13412345678','1234578@qq.com');
insert into client(name,sex,birthday,tel,Email) values('yang','f','1997-01-17','13412345678','1234578@qq.com');

insert into commodity(c_name,money,numer,facturers,date_time) values('mianbao',5,100,'beijing','2016-07-17');
insert into commodity(c_name,money,numer,facturers,date_time) values('niunai',7,190,'shanghai','2016-07-17');
insert into commodity(c_name,money,numer,facturers,date_time) values('jiuzi',10,500,'xian','2016-07-17');
insert into commodity(c_name,money,numer,facturers,date_time) values('people',3,300,'beijing','2016-07-17');
insert into commodity(c_name,money,numer,facturers,date_time) values('book',5,100,'shanghai','2016-07-17');

select * from client;
select * from commodity;

create table orderf(
	id integer not null auto_increment,
	c_id integer not null,
	o_id integer not null,
	count integer,
	d_time date,
	money integer,	
	PRIMARY KEY(`id`)
);

insert into orderf(c_id,o_id,count,d_time,money) values(1,1,30,'2016-09-01',90);
insert into orderf(c_id,o_id,count,d_time,money) values(4,2,40,'2016-09-02',100);
insert into orderf(c_id,o_id,count,d_time,money) values(2,5,20,'2016-08-29',80);
insert into orderf(c_id,o_id,count,d_time,money) values(3,3,50,'2016-08-30',100);
insert into orderf(c_id,o_id,count,d_time,money) values(5,4,60,'2016-09-01',110);

select c.id,c.name,c.tel,o.c_name,o.money,o.facturers,d.count,d.d_time,d.money
 from client c, commodity o, orderf d
 where d.c_id=c.id and d.o_id=o.id;
