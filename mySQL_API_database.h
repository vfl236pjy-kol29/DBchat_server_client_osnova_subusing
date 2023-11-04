#pragma once
#include <iostream>
#include <mysql.h>
# pragma comment(lib, "libmysql.lib")

class mySQL_API_database //����� ��� �������� � ����������� � ���� ������
{
public:
	mySQL_API_database(const std::string& host, const std::string& userName, const std::string& userPassword);//����������� ����� ������
	~mySQL_API_database();

	bool getStatus() const;
	std::string getName() const;
	MYSQL* getHandle();
	bool connect(const std::string& dbName);//������� �������� ����������� � ���� ������ dbName.
	bool create(const std::string& dbName);//������� ����������� �������� �� dbName.
	bool connectAnyWay(const std::string& dbName);//�������, ����������� ����������� � ������������ ��� � ������ ��� ��������� �� �� �����. �����
private:
	MYSQL _sqlHandle;
	bool _status;
	std::string _host;
	std::string _userName;
	std::string _userPassword;
	std::string _dbName;
};

