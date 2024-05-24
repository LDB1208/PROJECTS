-- 本程序演示SELECT语句
USE sql_store; -- 使用sql_store数据库

SELECT customer_id, first_name, birth_date -- 查找:后跟查找表格的列(*表示所有列)
FROM customers -- 指定需要查询的表
-- WHERE customer_id = 1 -- 过滤结果
ORDER BY first_name; -- 以此标准排序
