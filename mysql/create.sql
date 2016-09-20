show databases;

drop database IF EXISTS ren;

create database ren;

use ren;

drop table IF EXISTS register;
drop table IF EXISTS company;
drop table IF EXISTS personal;
drop table IF EXISTS primary_school;
drop table IF EXISTS high_school;
drop table IF EXISTS university;
drop table IF EXISTS relation;

create table register(		/*注册账户*/
	id integer not null auto_increment,
	account varchar(20),	/*账户*/
	password varchar(20),	/*密码*/
	p_id integer not null,	/*个人信息id*/
	PRIMARY  KEY(`id`)
);
create table personal(		/*建立注册表时的信息*/
	id integer not null auto_increment,
	name varchar(20),	/*姓名*/
	sex varchar(10),	/*性别*/
	birthday date,		/*生日*/
	tel varchar(20),	/*电话*/
	Email varchar(20),	/*电子邮箱*/
	c_id integer not null,	/*公司id*/
        p_id integer not null,	/*小学id*/
        h_id integer not null,	/*高中id*/
        u_id integer not null,	/*大学id*/
	PRIMARY  KEY(`id`)
);
create table company(		/*建立公司表的信息*/
	id integer not null auto_increment,
	c_name varchar(20),	/*公司名*/
	position varchar(20),	/*职位*/
	pay integer,		/*工资*/
	time_date date,		/*工作时间*/
	PRIMARY  KEY(`id`)
);
create table primary_school(
	id integer not null auto_increment,
	p_name varchar(20),	/*学校名*/
	attribute varchar(20),	/*属性*/
	P_date date,		/*上学时间*/
	address varchar(20),
	PRIMARY  KEY(`id`)
);
create table high_school(
        id integer not null auto_increment,
        h_name varchar(20),     /*学校名*/
        attribute varchar(20),  /*属性*/
	h_date date,		/*时间*/
	address varchar(20),
        PRIMARY  KEY(`id`)
);
create table university(
        id integer not null auto_increment,
        u_name varchar(20),     /*学校名*/
        attribute varchar(20),  /*属性*/
	u_date date,
	address varchar(20),
        PRIMARY  KEY(`id`)
);

insert into register(account,password,p_id) values('aaa','1111',2);
insert into register(account,password,p_id) values('aaa','1111',1);
insert into register(account,password,p_id) values('aaa','1111',3);


insert into personal(name,sex,birthday,tel,Email,c_id,p_id,h_id,u_id) values('zhang','f','1991-01-01','13412345678','1234578@qq.com',2,1,3,2);
insert into personal(name,sex,birthday,tel,Email,c_id,p_id,h_id,u_id) values('liu','m','1995-01-01','13412345678','1234578@qq.com',1,3,2,1);
insert into personal(name,sex,birthday,tel,Email,c_id,p_id,h_id,u_id) values('yang','m','1993-07-01','13412345678','1234578@qq.com',3,2,1,3);

insert into company(c_name,position,pay,time_date) values('huawei','zongcai',10000,'2016-06-07');
insert into company(c_name,position,pay,time_date) values('xiaomi','zongcai',20000,'2016-07-07');
insert into company(c_name,position,pay,time_date) values('xiaomi','zongcai',20000,'2016-07-07');

insert into primary_school(p_name,attribute,p_date,address) values('qinghua','xiaoxue','1999-09-1','weinan');
insert into primary_school(p_name,attribute,p_date,address) values('beida','xiaoxue','1998-09-1','yanglin');
insert into primary_school(p_name,attribute,p_date,address) values('xidian','xiaoxue','1999-09-1','shangnuo');

insert into high_school(h_name,attribute,h_date,address) values('qinghua','gaozhong','2008-09-1','ankang');
insert into high_school(h_name,attribute,h_date,address) values('beida','gaozhong','2007-09-1','hanzhong');
insert into high_school(h_name,attribute,h_date,address) values('jiangnan','gaozhong','2009-09-1','baoji');

insert into university(u_name,attribute,u_date,address) values('anda','daxue','2012-09-1','ankang');
insert into university(u_name,attribute,u_date,address) values('shida','daxue','2013-09-1','changan');
insert into university(u_name,attribute,u_date,address) values('jiaoda','daxue','2012-09-1','beilin');

select * from register;
select * from personal;
select * from company;
select * from primary_school;
select * from high_school;
select * from university;

create table relation(
	id integer not null auto_increment,
	r_id integer not null,
	friend varchar(20),
	colleague varchar(20),
	folk varchar(20),
	class varchar(20),
	PRIMARY  KEY(`id`)
);

insert into relation(r_id,friend,colleague,folk,class) values(2,'zhang','','','');
insert into relation(r_id,friend,colleague,folk,class) values(3,'','liu','','');
insert into relation(r_id,friend,colleague,folk,class) values(1,'','','yang','');
insert into relation(r_id,friend,colleague,folk,class) values(2,'','','','yang');

select p.name,p.sex,p.birthday,p.tel,p.Email,c.c_name,c.position,c.pay,c.time_date,re.friend,re.colleague,re.folk,re.class from register r,company c,personal p,primary_school p1,high_school h,university u,relation re where r.p_id=p.id and p.c_id=c.id and p.p_id=p1.id and p.h_id=h.id and p.u_id=u.id and re.r_id=p.id;
