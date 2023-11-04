#pragma once
#include <iostream>
#include <vector>
#include "mySQL_API_database.h"

class mySQL_API_table
{
public:
	mySQL_API_table(const std::string& tableName, mySQL_API_database* dbHandle, const std::vector<std::string>& columnTypes, const std::vector<std::string>& columnNames);

	bool checkIFColumnNamesOk(const std::vector<std::string>& columnNames);

	void insert(const std::vector<std::string>& columnNames, const std::vector<std::string>& values);
	std::string SelectOneRowWhereEqual(const std::string& fieldNameReturn, const std::string& fieldNameCompare, const std::string& compareValue);
	std::vector<std::string> SelectSeveralRowsWhereEqual(const std::string& fieldNameReturn, const std::string& fieldNameCompare, const std::string& compareValue);
	std::vector<std::string> SelectSeveralRowsWhereEqual2Fields(const std::string& fieldNameReturn, const std::string& fieldName1Compare, const std::string& compareValue1, const std::string& fieldName2Compare, const std::string& compareValue2);
	std::vector<std::string> SelectSeveralRowsWhereEqualAndIsNULL(const std::string& fieldNameReturn, const std::string& fieldNameCompare, const std::string& compareValue, const std::string& fieldNameIsNULL);

	void updateValuesWhereEqual(const std::string& fieldNameUpdate, const std::string& newValue, const std::string& fieldNameCompare, const std::string& compareValue);
	void updateValuesWhereEqualNoQuotes(const std::string& fieldNameUpdate, const std::string& newValue, const std::string& fieldNameCompare, const std::string& compareValue);

private:
	std::string _tableName;
	mySQL_API_database* _dbHandle;

};