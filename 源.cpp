#define _CRT_SECURE_NO_WARNINGS 1
SELECT* FROM homework.student;


ALTER TABLE student
DROP COLUMN address;
select* from student;

insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215121', '李勇', '男', 20, 'CS');
insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215122', '刘晨', '女', 19, 'CS');
insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215123', '王敏', '女', 19, 'MA');
insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215125', '张立', '男', 19, 'IS');
WHERE Sno in
(SELECT Sno
	FROM sc
	WHERE Cno = '3'
)
ORDER BY Sno DESC;

SELECT COUNT(*)
FROM student
where Ssex = '男'
group by Sdept;

SELECT Sdept 系,
sum(case when Ssex = '男' then 1 else 0 end) 男生人数,
sum(case when Ssex = '女' then 1 else 0 end) 女生人数,
MAX(CASE WHEN Ssex = '男' THEN Sage END) 男生最大年龄,
MAX(CASE WHEN Ssex = '女' THEN Sage END) 女生最大年龄
FROM student
GROUP BY Sdept
ORDER BY Sdept;
SELECT* FROM homework.course;
insert into course(Cno, Cname)values('1', 'DB_design');
insert into course(Cno, Cname)values('2', '数学');
insert into course(Cno, Cname)values('3', '信息系统');
insert into course(Cno, Cname)values('4', '操作系统');
insert into course(Cno, Cname)values('5', '数据结构');
insert into course(Cno, Cname)values('6', '数据处理');
insert into course(Cno, Cname)values('7', 'PASCAL语言');
update COURSE set Cpno = '5', Ccredit = 4 where Cno = '1';
update COURSE set Cpno = NULL, Ccredit = 2 where Cno = '2';
update COURSE set Cpno = '1', Ccredit = 4 where Cno = '3';
update COURSE set Cpno = '6', Ccredit = 3 where Cno = '4';
update COURSE set Cpno = '7', Ccredit = 4 where Cno = '5';
update COURSE set Cpno = NULL, Ccredit = 2 where Cno = '6';
update COURSE set Cpno = '6', Ccredit = 4 where Cno = '7';
SELECT* FROM homework.sc;
insert into SC(Sno, Cno, Grade) values('201215121', '1', 92);
insert into SC(Sno, Cno, Grade) values('201215121', '2', 85);
insert into SC(Sno, Cno, Grade) values('201215121', '3', 88);
insert into SC(Sno, Cno, Grade) values('201215122', '2', 59);
insert into SC(Sno, Cno, Grade) values('201215122', '3', 80);
