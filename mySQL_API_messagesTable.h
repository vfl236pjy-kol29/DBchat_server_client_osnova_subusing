#pragma once
#include "mySQL_API_table.h"
#include<iostream>


class mySQL_API_messagesTable :public mySQL_API_table
{
		public:
			mySQL_API_messagesTable(mySQL_API_database* dbHandle);
			void addMessage(const std::string& senderID, const std::string& receiverID, const std::string& text);

			const std::string getSenderByID(const std::string& messageID);
			const std::string getReceiverByID(const std::string& messageID);
			const std::string getTextByID(const std::string& messageID);
			const std::string getSendTimeByID(const std::string& messageID);
			const std::string getReceivedTimeByID(const std::string& messageID);

			std::vector<std::string>getUnreceivedMessagesIDsForUserID(const std::string& receiverID);

			void setReceived(const std::string& messageID);
			void setReceivedMultiple( std::vector<std::string> messagesIDs);

		private:




};