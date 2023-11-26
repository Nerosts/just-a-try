#define _CRT_SECURE_NO_WARNINGS 1
//数据库实验代码
select a.*
from student a inner join student b on a.Sno = b.Sno
where  a.Sdept = '信息系' and b.Sage < 20

    select *
    from student a
where a.Sdept = 'MA' and not exists(
    select *
    from student b
where b.Sage < 20 and b.Sno = a.Sno
    )

    DELIMITER //
    CREATE TRIGGER sex_trigger
    BEFORE INSERT ON student
    FOR EACH ROW
    BEGIN
    IF NEW.Ssex != '男' AND NEW.Ssex != '女' THEN
    SET NEW.Ssex = '男';
END IF;
END;
//
DELIMITER;

DELIMITER //
CREATE TRIGGER update_sc_trigger
AFTER UPDATE ON student
FOR EACH ROW
BEGIN
IF OLD.Sno != NEW.Sno THEN
UPDATE sc
SET Sno = NEW.Sno
WHERE Sno = OLD.Sno;
END IF;
END;
//
DELIMITER;

DELIMITER //
CREATE TRIGGER delete_sc_trigger
BEFORE DELETE ON student
FOR EACH ROW
BEGIN
DELETE FROM sc
WHERE Sno = OLD.Sno;
END;
//
DELIMITER;

INSERT INTO sc(sno, cno, grade) VALUES(2, 'C002', 78);

insert into STUDENT(Sno, Sname, Ssex, Sage, Sdept) values('201215129', '李勇', '?', 20, 'CS');

SELECT*
FROM student;

