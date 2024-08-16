ATTACH DATABASE 'sys.db' AS 'test'; -- 附加一个现有的数据库sys.db
ATTACH DATABASE 'new.db' AS 'new'; -- 新建一个数据库new.db
DETACH DATABASE 'test';
DETACH DATABASE 'new';