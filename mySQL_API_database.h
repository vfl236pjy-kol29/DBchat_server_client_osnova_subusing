#pragma once
#include <iostream>
#include <mysql.h>
# pragma comment(lib, "libmysql.lib")

class mySQL_API_database //Класс для создания и подключения к базе данных
{
public:
	mySQL_API_database(const std::string& host, const std::string& userName, const std::string& userPassword);//определение полей класса
	~mySQL_API_database();

	bool getStatus() const;
	std::string getName() const;
	MYSQL* getHandle();
	bool connect(const std::string& dbName);//функция проверки подключения к базе данных dbName.
	bool create(const std::string& dbName);//функция проверяющая создание БД dbName.
	bool connectAnyWay(const std::string& dbName);//функция, проверяющая подключение к существующей или к только что созданной БД по соотв. имени
private:
	MYSQL _sqlHandle;
	bool _status;
	std::string _host;
	std::string _userName;
	std::string _userPassword;
	std::string _dbName;
};

