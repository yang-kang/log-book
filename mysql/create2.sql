-- http://doc.mysql.cn/mysql5/refman-5.1-zh.html-chapter/

show databases;

drop database IF EXISTS ypf;

show tables;

create database ypf;

use ypf;

drop table IF EXISTS shu;
drop table IF EXISTS user1;
drop table IF EXISTS jieshu;


create table shu(
	id integer not NULL auto_increment,
	name varchar(20),
	auther varchar(20),
	jiage integer,
	ISBN varchar(50),
	chubanshe varchar(60),
	PRIMARY KEY (`id`)
);
 desc shu;

insert into shu(name,auther,jiage,ISBN,chubanshe)
	values('shujujiegou','wuweimin',39,'7-900643-22-2','qinghuadaxuechubanshe');
insert into shu(name,auther,jiage,ISBN,chubanshe)
	values('shujuku','zhao',34,'7-900222-22-2','renmindaxuechubanshe');
insert into shu(name,auther,jiage,ISBN,chubanshe)
	values('JAVA','zhang',50,'7-901243-22-2','renmingjiaoyuchubanshe');
insert into shu(name,auther,jiage,ISBN,chubanshe)
	values('SQL','Long',39,'7-900643-23-3','qinghuadaxuechubanshe');
insert into shu(name,auther,jiage,ISBN,chubanshe)
	values('C++','Zheng',48,'7-910643-22-2','qinghuadaxuechubanshe');
select * from shu;
update shu set name='C' where id=1;

 create table user1(
	id integer not NULL auto_increment,
	name varchar(20),
	sex varchar(10),
	age integer,
	tel varchar(13),
	Email varchar(15),
	PRIMARY KEY (`id`)
);
 desc user1;

insert into user1(name,sex,age,tel,Email)
	values('zhang','boy','23','13412345678','1234578@qq.com');
insert into user1(name,sex,age,tel,Email)
	values('wu','girl','20','13412345687','1234512@qq.com');
insert into user1(name,sex,age,tel,Email)
	values('zhou','boy','21','1341234123','12345342@qq.com');
insert into user1(name,sex,age,tel,Email)
	values('Li','girl','20','13412345123','123452213@qq.com');

select * from shu;
select * from user1;

create table jieshu(
	shu_id integer not null,
	user_id integer not null,
	jieshu_time datetime not null default now()
);

insert into jieshu (shu_id,user_id) values(1,1);
insert into jieshu (shu_id,user_id) values(2,2);
insert into jieshu (shu_id,user_id) values(3,3);
insert into jieshu (shu_id,user_id) values(4,1);
insert into jieshu (shu_id,user_id) values(5,2);

select u.id,u.name,s.name,now() - j.jieshu_time
 from jieshu j, user1 u, shu s
 where j.user_id=u.id and j.shu_id=s.id;
