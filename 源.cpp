#define _CRT_SECURE_NO_WARNINGS 1
SELECT* FROM homework.student;


ALTER TABLE student
DROP COLUMN address;
select* from student;

insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215121', '����', '��', 20, 'CS');
insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215122', '����', 'Ů', 19, 'CS');
insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215123', '����', 'Ů', 19, 'MA');
insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215125', '����', '��', 19, 'IS');
WHERE Sno in
(SELECT Sno
	FROM sc
	WHERE Cno = '3'
)
ORDER BY Sno DESC;

SELECT COUNT(*)
FROM student
where Ssex = '��'
group by Sdept;

SELECT Sdept ϵ,
sum(case when Ssex = '��' then 1 else 0 end) ��������,
sum(case when Ssex = 'Ů' then 1 else 0 end) Ů������,
MAX(CASE WHEN Ssex = '��' THEN Sage END) �����������,
MAX(CASE WHEN Ssex = 'Ů' THEN Sage END) Ů���������
FROM student
GROUP BY Sdept
ORDER BY Sdept;
SELECT* FROM homework.course;
insert into course(Cno, Cname)values('1', 'DB_design');
insert into course(Cno, Cname)values('2', '��ѧ');
insert into course(Cno, Cname)values('3', '��Ϣϵͳ');
insert into course(Cno, Cname)values('4', '����ϵͳ');
insert into course(Cno, Cname)values('5', '���ݽṹ');
insert into course(Cno, Cname)values('6', '���ݴ���');
insert into course(Cno, Cname)values('7', 'PASCAL����');
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
