#include <iostream>
#include <mysql.h>

MYSQL* conn;
//MYSQL_RES *res;
//MYSQL_ROW row;

int main() {
    conn = mysql_init(nullptr);
    /*�������ݿⲿ��*/

    /*����������ݿ���Ϣ*/
    const char* server = "localhost";
    const char* user = "root";
    const char* password = "ldb1208";
    const char* database = "mysql";

    /*��������*/
    if (!mysql_real_connect(conn, server, user, password, database, 0, nullptr, 0)) {
        std::cerr << "���ݿ�����ʧ��: " << mysql_error(conn) << std::endl;
        return 1;
    }
    else {
        std::cout << "���ӳɹ�" << std::endl;
    }

    /*�ر����ݿ�*/
    mysql_close(conn);
    return 0;
}
