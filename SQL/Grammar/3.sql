-- Exercise: Return all your projects
--     name
--     unit price
--     new price (unit price * 1.1)
SELECT name, unit_price, unit_price * 1.1 AS new_price
FROM products;

-- 本程序演示WHERE
SELECT *
FROM Customers
WHERE state = 'va' -- 不区分大小写
OR points > 3000;

SELECT *
FROM Customers
WHERE state <> 'va'; -- <>表示其它

SELECT *
FROM Customers
WHERE birth_date > '1990-01-01'; -- 筛选1990-01-01后出生的用户