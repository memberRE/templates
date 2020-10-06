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
```



## 技巧

- 建立多对多的关系的时候，可以建一个中间表。例如老师与班级的对应关系，可以建一个表，每一项由teacher_id 与 class_id构成。
- 可以将一个大表拆成多个小表，小标在查询的时候速度快，所以一般把大表根据列的使用频率分成多个表。
- 索引的优点是提高了查询效率，缺点是在插入、更新和删除记录时，需要同时修改索引，因此，**索引越多，插入、更新和删除记录的速度就越慢**。对于主键，关系数据库会**自动对其创建主键索引**。使用主键索引的效率是最高的，因为主键会保证绝对唯一。