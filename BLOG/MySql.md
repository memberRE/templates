# MySql

## 关键字

```mysql
# 外键相关
ALTER TABLE tableName
ADD CONSTRAINT fk_class_id 	#添加外键约束（影响性能，完全可以靠程序的逻辑来保证）
FOREIGN KEY (class_id) 		#定义class_id为外键
REFERENCES classes (id);	#链接这个外键到表classes的id项
DROP FOREIGN KEY fk_class_id;#删除外键约束（不删除外键） 
```

```mysql
# 索引相关
ALTER TABLE students
ADD INDEX %索引名称% (%索引的列%,....);#可以有多个
```

```mysql
SHOW DATABASES
```

```mysql
CREATE TABLE IF NOT EXISTS `userdata`(
   `runoob_id` INT UNSIGNED AUTO_INCREMENT,
   `runoob_title` VARCHAR(100) NOT NULL,
   `runoob_author` VARCHAR(40) NOT NULL,
   `submission_date` DATE,
   PRIMARY KEY ( `runoob_id` )
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS S (
   SNO VARCHAR(40) NOT NULL,
   SNAME VARCHAR(40) NOT NULL,
   STATUS VARCHAR(40) NOT NULL,
   CITY VARCHAR(40) NOT NULL,
   PRIMARY KEY ( SNO )
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS P (
   PNO VARCHAR(40) NOT NULL,
   PNAME VARCHAR(40) NOT NULL,
   COLOR VARCHAR(40) NOT NULL,
   WEIGHT INT(10) NOT NULL,
   PRIMARY KEY ( PNO )
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS J (
   JNO VARCHAR(40) NOT NULL,
   JNAME VARCHAR(40) NOT NULL,
   CITY VARCHAR(40) NOT NULL,
   PRIMARY KEY ( JNO )
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS SPJ (
   SNO VARCHAR(40) NOT NULL,
    PNO VARCHAR(40) NOT NULL,
    JNO VARCHAR(40) NOT NULL,
   QTY INT(10) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

```mysql
插入
INSERT INTO S 
VALUES
('S1','精益','20','天津'),
('S2','盛锡','10','北京'),
('S3','东方红','30','北京'),
('S4','丰泰盛','20','天津'),
('S5','为民','30','上海');

INSERT INTO P 
VALUES
('P1','螺母','红',12),
('P2','螺栓','绿',17),
('P3','螺丝刀','蓝',14),
('P4','螺丝刀','红',14),
('P5','凸轮','蓝',40),
('P6','齿轮','红',30);

INSERT INTO J 
VALUES
('J1','三建','北京'),
('J2','一汽','长春'),
('J3','弹簧厂','天津'),
('J4','造船厂','天津'),
('J5','机车厂','唐山'),
('J6','无线电厂','常州'),
('J7','半导体厂','南京');

INSERT INTO SPJ 
VALUES
('S1','P1','J1',200),
('S1','P1','J3',100),
('S1','P1','J4',700),
('S1','P2','J2',100),
('S2','P3','J1',400),
('S2','P3','J2',200),
('S2','P3','J4',500),
('S2','P3','J5',400),
('S2','P5','J1',400),
('S2','P5','J2',100),
('S3','P1','J1',200),
('S3','P3','J1',200),
('S4','P5','J1',100),
('S4','P6','J3',300),
('S4','P6','J4',200),
('S5','P2','J4',100),
('S5','P3','J1',200),
('S5','P6','J2',200),
('S5','P6','J4',500);
```



## 技巧

- 建立多对多的关系的时候，可以建一个中间表。例如老师与班级的对应关系，可以建一个表，每一项由teacher_id 与 class_id构成。
- 可以将一个大表拆成多个小表，小标在查询的时候速度快，所以一般把大表根据列的使用频率分成多个表。
- 索引的优点是提高了查询效率，缺点是在插入、更新和删除记录时，需要同时修改索引，因此，**索引越多，插入、更新和删除记录的速度就越慢**。对于主键，关系数据库会**自动对其创建主键索引**。使用主键索引的效率是最高的，因为主键会保证绝对唯一。