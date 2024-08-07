#include <iostream>
#include <mysql.h>

MYSQL* conn;
//MYSQL_RES *res;
//MYSQL_ROW row;

int main() {
    conn = mysql_init(nullptr);
    /*连接数据库部分*/

    /*输入你的数据库信息*/
    const char* server = "localhost";
    const char* user = "root";
    const char* password = "ldb1208";
    const char* database = "mysql";

    /*尝试连接*/
    if (!mysql_real_connect(conn, server, user, password, database, 0, nullptr, 0)) {
        std::cerr << "数据库连接失败: " << mysql_error(conn) << std::endl;
        return 1;
    }
    else {
        std::cout << "连接成功" << std::endl;
    }

    /*关闭数据库*/
    mysql_close(conn);
    return 0;
}
