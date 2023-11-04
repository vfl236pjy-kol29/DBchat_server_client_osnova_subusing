#pragma once
#include "mySQL_API_table.h"
#include<iostream>


class mySQL_API_usersTable :public mySQL_API_table
{
	public:
		mySQL_API_usersTable(mySQL_API_database* dbHandle);
		~mySQL_API_usersTable();

		std::string getIDbyLogin(const std::string& userLogin);
		const std::string getLoginByID(const std::string& userID);
		const std::string getPwHashByID(const std::string& userID);
		const std::string getNameByID(const std::string& userID);
		const std::string getLoginByID(const std::string& userID);
		const std::string getRegDateByID(const std::string& userID);
		const std::string getEmailByID(const std::string& userID);
		const std::string getStatusByID(const std::string& userID);

		void setOnLine(const std::string& userID);
		void setOffLine(const std::string& userID);
		bool IsOnLine(const std::string& userID);
		bool IsOffLine(const std::string& userID);
		bool Deleted(const std::string& userID);

		bool addUser(const std::string& userLogin, const std::string& userPwHash, const std::string& userName, const std::string& Email);
		bool deleteUser(const std::string& userLogin);
		bool Login(const std::string& userLogin, const std::string& userPwHash);
		bool Logout(const std::string& userLogin);

	private:
};