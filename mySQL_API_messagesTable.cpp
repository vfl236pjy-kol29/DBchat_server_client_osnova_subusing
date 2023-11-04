#include"mySQL_API_messagesTable.h"
#include<iostream>
#include"mySQL_API_constants.h"
using namespace std;




mySQL_API_messagesTable::mySQL_API_messagesTable(mySQL_API_database* dbHandle) : mySQL_API_table(constMessagesTable_name, dbHandle, constMessagesTable_collumnTypes,constMessagesTable_collumnNames) {}
mySQL_API_messagesTable::~mySQL_API_messagesTable()
{
	updateValuesWhereEqual(constUsr_status, "offline", constUsr_status, "online");//???????????????????????????????????
}



void mySQL_API_messagesTable::addMessage(const std::string& senderID, const std::string& receiverID, const std::string& text)
{
	//if ((senderID.empty()) || (receiverID.empty()) || (text.empty()))
	//{
	//	std::cout << "Беда! Нет данных в таблице" << std::endl;
	//	return false;
	//}
	std::string idExists = getTextByID(constMsg_ID);
	if (idExists.empty())
	{
		std::vector<std::string>collumnNames = { constMsg_sender,  constMsg_receiver,constMsg_text};
		std::vector<std::string>values = { senderID, receiverID, text};
		insert(collumnNames, values);
	
	}
	else
	{
		return;
	}
}



const std::string mySQL_API_messagesTable::getSenderByID(const std::string& messageID)
{
	return SelectOneRowWhereEqual(constMsg_sender, constMsg_ID, messageID);
}

const std::string mySQL_API_messagesTable::getReceiverByID(const std::string& messageID)
{
	return SelectOneRowWhereEqual(constMsg_receiver, constMsg_ID, messageID);
}

const std::string mySQL_API_messagesTable::getTextByID(const std::string& messageID)
{
	return SelectOneRowWhereEqual(constMsg_text, constMsg_ID, messageID);
}

const std::string mySQL_API_messagesTable::getSendTimeByID(const std::string& messageID)
{
	return SelectOneRowWhereEqual(constMsg_send, constMsg_ID, messageID);
}

const std::string mySQL_API_messagesTable::getReceivedTimeByID(const std::string& messageID)
{
	return SelectOneRowWhereEqual(constMsg_received, constMsg_ID, messageID);
}


std::vector<std::string>mySQL_API_messagesTable::getUnreceivedMessagesIDsForUserID(const std::string& receiverID)
{


}


void mySQL_API_messagesTable::setReceived(const std::string& messageID)
{
	if (getReceivedTimeByID(messageID))
	{
	}

}

void mySQL_API_messagesTable::setReceivedMultiple(std::vector<std::string> messagesIDs)
{


}