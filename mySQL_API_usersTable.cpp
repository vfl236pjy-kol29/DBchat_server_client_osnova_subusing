#include "mySQL_API_usersTable.h"
#include<iostream>
#include"mySQL_API_constants.h"
using namespace std;

mySQL_API_usersTable::mySQL_API_usersTable(mySQL_API_database* dbHandle): mySQL_API_table(constUsersTable_name, dbHandle, constUsersTable_collumnTypes, constUsersTable_collumnNames)  {}
mySQL_API_usersTable::~mySQL_API_usersTable()
{
	updateValuesWhereEqual(constUsr_status, "offline", constUsr_status, "online");
}

std::string mySQL_API_usersTable::getIDbyLogin(const std::string& userLogin)
{
	return SelectOneRowWhereEqual(constUsr_ID, constUsr_login, userLogin);
}

const std::string mySQL_API_usersTable::getLoginByID(const std::string& userID)
{
	return SelectOneRowWhereEqual(constUsr_ID, constUsr_login, userID);
}

const std::string mySQL_API_usersTable::getPwHashByID(const std::string& userID)
{
	return SelectOneRowWhereEqual(constUsr_hash, constUsr_ID, userID);
}

const std::string mySQL_API_usersTable::getNameByID(const std::string& userID)
{
	return SelectOneRowWhereEqual(constUsr_name, constUsr_ID, userID);
}

const std::string mySQL_API_usersTable::getRegDateByID(const std::string& userID)
{
	return SelectOneRowWhereEqual(constUsr_regDate, constUsr_ID, userID);
}

const std::string mySQL_API_usersTable::getEmailByID(const std::string& userID)
{
	return SelectOneRowWhereEqual(constUsr_eMail, constUsr_ID, userID);
}

const std::string mySQL_API_usersTable::getStatusByID(const std::string& userID)
{
	return SelectOneRowWhereEqual(constUsr_status, constUsr_ID, userID);
}

void mySQL_API_usersTable::setOnLine(const std::string& userID)
{
	updateValuesWhereEqual(constUsr_status, "online", constUsr_ID, "offline");
}

void mySQL_API_usersTable::setOffLine(const std::string& userID)
{
	updateValuesWhereEqual(constUsr_status, "offline", constUsr_ID, userID);
}

bool mySQL_API_usersTable::IsOnLine(const std::string& userID)
{
	std::string statusStr = SelectOneRowWhereEqual(constUsr_status, constUsr_ID, userID);
	if (statusStr.compare("online") == 0) return true; else return false;
}

bool mySQL_API_usersTable::IsOffLine(const std::string& userID)
{
	std::string statusStr = SelectOneRowWhereEqual(constUsr_status, constUsr_ID, userID);
	if (statusStr.compare("offline") == 0) return true; else return false;
}

bool mySQL_API_usersTable::Deleted(const std::string& userID)
{
	std::string statusStr = SelectOneRowWhereEqual(constUsr_status, constUsr_ID, userID);
	if (statusStr.compare("deleted") == 0) return true; else return false;
}

bool mySQL_API_usersTable::addUser(const std::string& userLogin, const std::string& userPwHash, const std::string& userName, const std::string& Email)
{
	if ((userLogin.empty()) || (userPwHash.empty()) || (userName.empty()) || (Email.empty()))
	{
		std::cout << "Беда! Нет данных в таблице" << std::endl;
		return false;
	}
	std::string idExists = getIDbyLogin(userLogin);
	if (idExists.empty())
	{
		std::vector<std::string>collumnNames = { constUsr_login,  constUsr_hash,   constUsr_name, constUsr_eMail};
		std::vector<std::string>values = {userLogin, userPwHash, userName, Email};
		insert(collumnNames, values);
		std::cout << "Удачно добавлен новый пользователь!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Добавляемый пользователь уже существует!" << std::endl;
		return false;
	}
}

bool mySQL_API_usersTable::deleteUser(const std::string& userLogin)
{
	std::string idExists = getIDbyLogin(userLogin);
	if (!idExists.empty())
	{
		if (Deleted(idExists))
		{
			std::cout << "Этот пользователь" << userLogin << "уже удалён" << std::endl;
			return true;
		}
		updateValuesWhereEqual(constUsr_status, "deleted", constUsr_ID, idExists);
		updateValuesWhereEqual(constUsr_hash, " ", constUsr_ID, idExists);
		std::cout << "Удачно удалённый пользователь" << userLogin << "Из БД" << std::endl;
		return true;
	}
		else
		{
		std::cout << "Удалённый пользователь" << userLogin << "неизвестен" << std::endl;
		return false;
		}
}

bool mySQL_API_usersTable::Login(const std::string& userLogin, const std::string& userPwHash)
{
	std::string idExists = getIDbyLogin(userLogin);
	if (!idExists.empty())
	{
		if (Deleted(idExists))
		{
			std::cout << "Этот пользователь" << userLogin << "уже удалён" << std::endl;
			return false;
		}
		std::string bdHash = getPwHashByID(idExists);
		if (bdHash.compare(userPwHash) == 0)
		{
			setOnLine(idExists);
			std::cout << "User" << userLogin << "succefuly registered" << std::endl;
			updateValuesWhereEqualNoQuotes(constUsr_last_login, "current_timestamp", constUsr_ID, idExists);
			return true;
		}
		else
		{
			std::cout << "Неверный пароль пользователя" << userLogin << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Кто это? Неизвестный пользователь--" << userLogin << std::endl;
		return false;
	}
}

bool mySQL_API_usersTable::Logout(const std::string& userLogin)
{
	return false;
}

bool mySQL_API_usersTable::Logout(const std::string& userLogin)
{
	std::string idExists = getIDbyLogin(userLogin);
	if (!idExists.empty())
	{
		if (IsOnLine(idExists))
		{
			setOffLine(idExists);
			updateValuesWhereEqualNoQuotes(constUsr_last_login, "current_timestamp", constUsr_ID, idExists);
			std::cout << "Пользователь" << userLogin << "вышел" << std::endl;
			return true;
		}
		if (IsOffLine(idExists))
		{
			std::cout << "Пользователь" << userLogin << "активен" << std::endl;
			return true;
		}
		if (Deleted(idExists))
		{
			std::cout << "Пользователь" << userLogin << "изничтожен" << std::endl;
			return false;
		}
}