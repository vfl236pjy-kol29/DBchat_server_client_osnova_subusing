
#include <iostream>
#include<mysql.h>
#include "mySQL_API_database.h"
#include "mySQL_API_database.h"


mySQL_API_database::mySQL_API_database(const std::string& host, const std::string& userName, const std::string& userPassword) :_host(host), _userName(userName), _userPassword(userPassword), _status(false) {};

mySQL_API_database::~mySQL_API_database()
{
	mysql_close(&_sqlHandle);
	_status = false;
}

bool mySQL_API_database::getStatus() const
{
	return _status;
}

std::string mySQL_API_database::getName() const
{
	return _dbName;
}

MYSQL* mySQL_API_database::getHandle()
{
	return &_sqlHandle;
}

bool mySQL_API_database::connect(const std::string& dbName)
{
	_dbName = dbName;
	mysql_init(&_sqlHandle);
	if (&_sqlHandle == nullptr)
	{
		std::cout << "Дескриптор не получен. Беда!" << std::endl;
		_status = false;
		return _status;
	}
	if (!mysql_real_connect(&_sqlHandle, _host.c_str(), _userName.c_str(), _userPassword.c_str(), _dbName.c_str(), NULL, NULL, 0))
	{
		std::cout << "Ошибка соединения с БД" << mysql_error(&_sqlHandle) << std::endl;
		_status = false;
		return _status;
	}
	else
	{
		if (!_dbName.empty())
		{
			std::cout << "Есть контакт с БД " << _dbName << std::endl;
			 _status = true;
		}
		mysql_set_character_set(&_sqlHandle, "utf8mb4");
		return _status;
	}
}

bool mySQL_API_database::create(const std::string& dbName)
{
	std::string reg = "create database if not exist" + dbName;
	if (connect(" "))
	{
		if (mysql_query(&_sqlHandle, reg.c_str())) return true;
	}
	return false;
}

bool mySQL_API_database::connectAnyWay(const std::string& dbName)
{
	create(dbName);
	return connect(dbName);
}

