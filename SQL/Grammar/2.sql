-- 本程序演示进阶SELECT语句

-- 修改第1行state为MA
UPDATE sql_store.customers t SET t.state = 'MA' WHERE t.customer_id = 1;

SELECT -- 多行SELECT
    first_name,
    last_name,
    points,
    (points + 20) * 5, -- 使用算术表达式(遵循运算优先级)
    (points + 20) * 5 AS "discount factor" -- AS别名(多个单词需用引号)
FROM customers;

-- 修改第1行state为VA
UPDATE sql_store.customers t SET t.state = 'VA' WHERE t.customer_id = 1;

SELECT DISTINCT state -- DISTINCT删除相同数据
FROM customers;
