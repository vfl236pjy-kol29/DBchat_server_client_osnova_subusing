#include<iostream>
#include"mySQL_API_database.h"
#include"mySQL_API_messagesTable.h"
#include"mySQL_API_usersTable.h"

constexpr const char* constDB_host = "localhost";
constexpr const char* constDB_name = "new_testDB";
constexpr const char* constDB_user = "user";
constexpr const char* constDB_password = "password";

int main()
{
	setlocale(LC_ALL, "rus");
	mySQL_API_database ChatDB(constDB_host, constDB_user, constDB_password );
	ChatDB.connectAnyWay(constDB_name);
	mySQL_API_usersTable ChatUsers(&ChatDB);
	mySQL_API_messagesTable ChatMessages(& ChatDB);








	return 0;
}