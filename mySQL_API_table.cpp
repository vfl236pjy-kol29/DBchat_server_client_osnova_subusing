#include "mySQL_API_table.h"
#include<iostream>


mySQL_API_table::mySQL_API_table(const std::string& tableName, mySQL_API_database* dbHandle, const std::vector<std::string>& columnTypes, const std::vector<std::string>& columnNames) :_tableName(tableName), _dbHandle(dbHandle)
{
	std::string reg;
	if (!checkIFColumnNamesOk(columnNames))
	{
		std::cout << "ОШИБКА соединения к" << tableName << "in" << _dbHandle->getName() << "!" << std::endl;
		return;
	}
	else
	{
		reg = "create table if not exists" + _tableName + "(";
		for (size_t i = 0; i < columnTypes.size(); i++)
		{
			if (i != 0)
			{
				reg = reg + ",";
				reg = reg + columnNames.at(i) + " " + columnTypes.at(i);
			}
			reg = reg + ",";
			mysql_query(_dbHandle->getHandle(), reg.c_str());
		}
	}
}

bool mySQL_API_table::checkIFColumnNamesOk(const std::vector<std::string>& columnNames)
{
	std::string tmpStr;
	std::vector<std::string>tmpVect;
	bool tableExists = false;
	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string reg = "select columnName from information_schema.columns where table_schema=' " + _dbHandle->getName() + "' and table_name=' " + _tableName + " '  ";
	mysql_query(_dbHandle->getHandle(), reg.c_str());
	std::cout << "select request: " << reg << std::endl;
	if (res = mysql_store_result(_dbHandle->getHandle()))
	{
		while (row = mysql_fetch_row(res))
		{
			tableExists = true;
			if (mysql_num_fields(res) == 0)
			{
				std::cout << "Таблица без столбцов" << std::endl;
				return false;
			}
			tmpStr = row[0];
			tmpVect.push_back(tmpStr);
		}
		if (tableExists)
		{
			if (tmpVect.size() != columnNames.size())
			{
				std::cout << "Таблица в наличии, но несовпадение по числу колонок" << std::endl;
				return false;
			}
		}
	}
	else
	{
		std::cout << "Problemm" << mysql_error(_dbHandle->getHandle()) << std::endl;
		return false;
	}
	return true;
}

void mySQL_API_table::insert(const std::vector<std::string>& columnNames, const std::vector<std::string>& values)
{
	std::string reg = "insert" + _tableName + "(";
		for (size_t i = 0; i < columnNames.size(); i++)
		{
			if (i != 0)
			{
			reg = reg + ",";
			reg = reg + columnNames.at(i) + " ";
			}
		}
		reg = reg + ")values(";
		for (size_t i = 0; i < values.size(); i++)
		{
			if (i != 0)
			{
				reg = reg + ",";
				reg = reg + "'" + values.at(i) + "'";
			}
		}
		reg = reg + ")";
		std::cout << "insert request" << reg << std::endl;
		mysql_query(_dbHandle->getHandle(), reg.c_str());	
}

std::string mySQL_API_table::SelectOneRowWhereEqual(const std::string& fieldNameReturn, const std::string& fieldNameCompare, const std::string& compareValue)
{
	std::vector<std::string>tmpVect = SelectSeveralRowsWhereEqual(fieldNameReturn, fieldNameCompare, compareValue);
	std::string retVal;
	if (tmpVect.size() == 0)
	{
		std::cout << "select returned null" << std::endl;
		return std::string();
	}
	if (tmpVect.size() > 1)
	{
		std::cout << "select returned several rows" << std::endl;
	}
	retVal = tmpVect[0];
	return retVal;
}

std::vector<std::string>mySQL_API_table::SelectSeveralRowsWhereEqual(const std::string& fieldNameReturn, const std::string& fieldNameCompare, const std::string& compareValue)
{
	std::vector<std::string>retVal;
	std::string tmpStr;
	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string reg = "select" + fieldNameReturn + "from" + _tableName + "where" + fieldNameCompare + "'" + compareValue + "'";
	std::cout << "select request" << reg << std::endl;

}

void mySQL_API_table::updateValuesWhereEqual(const std::string& fieldNameUpdate, const std::string& newValue, const std::string& fieldNameCompare, const std::string& compareValue)
{


}


void mySQL_API_table::updateValuesWhereEqualNoQuotes(const std::string& fieldNameUpdate, const std::string& newValue, const std::string& fieldNameCompare, const std::string& compareValue)
{


}

std::vector<std::string>mySQL_API_table:: SelectSeveralRowsWhereEqual2Fields(const std::string& fieldNameReturn, const std::string& fieldName1Compare, const std::string& compareValue1, const std::string& fieldName2Compare, const std::string& compareValue2)
{

}

std::vector<std::string>mySQL_API_table::SelectSeveralRowsWhereEqualAndIsNULL(const std::string& fieldNameReturn, const std::string& fieldNameCompare, const std::string& compareValue, const std::string& fieldNameIsNULL)
{


}