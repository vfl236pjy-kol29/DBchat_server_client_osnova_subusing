#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//константы класса UsersTable
constexpr const char* constUsersTable_name = "users";//им€ таблицы ѕќЋ№«ќ¬ј“≈Ћ»
//список имЄн и типов столбцов таблицы ѕќЋ№«ќ¬ј“≈Ћ»
constexpr const char* constUsr_ID = "id";
constexpr const char* constUsrType_ID = "int auto_increment primary key";
constexpr const char* constUsr_login = "Login";
constexpr const char* constUsrType_login = "varchar(40) not null";
constexpr const char* constUsr_hash = "pw_hash";
constexpr const char* constUsrType_hash = "varchar(40) not null";
constexpr const char* constUsr_name = "name";
constexpr const char* constUsrType_name = "varchar(40) not null";
constexpr const char* constUsr_regDate = "reg.date";
constexpr const char* constUsrType_regDate = "timestamp default current_timestamp";
constexpr const char* constUsr_eMail = "eMail";
constexpr const char* constUsrType_eMail = "varchar(40)";
constexpr const char* constUsr_status = "status";
constexpr const char* constUsrType_status = "varchar (20) default 'offline'";
constexpr const char* constUsr_last_login = "last_login";
constexpr const char* constUsrType_last_login = "timestamp default null";

//¬ектора имЄн и типов столбцов таблицы ѕќЋ№«ќ¬ј“≈Ћ»
const std::vector <std::string> constUsersTable_collumnNames = { constUsr_ID,   constUsr_login,  constUsr_hash,   constUsr_name,   constUsr_regDate,   constUsr_eMail,   constUsr_status,   constUsr_last_login };
const std::vector<std::string> constUsersTable_collumnTypes = { constUsrType_ID,  constUsrType_login,  constUsrType_hash,  constUsrType_name,  constUsrType_regDate,  constUsrType_eMail,  constUsrType_status,  constUsrType_last_login};


// онстанты класса messagesTable и ниже соответствующие вектора
constexpr const char* constMessagesTable_name = "messages";
constexpr const char* constMsg_ID = "id";
constexpr const char* constMsgType_ID = "int auto_increment primary key";
constexpr const char* constMsg_sender = "sender_ID";
constexpr const char* constMsgType_sender = "int not null references users(ID)";
constexpr const char* constMsg_text = "text";
constexpr const char* constMsgType_text = "text";
constexpr const char* constMsg_receiver= "receiver_ID";
constexpr const char* constMsgType_receiver = "int not null references users(ID)";
constexpr const char* constMsg_send = "send_time";
constexpr const char* constMsgType_send = "timestamp default current_timestamp";
constexpr const char* constMsg_received = "received_time";
constexpr const char* constMsgType_received = "timestamp default null";

const std::vector <std::string> constMessagesTable_collumnNames = { constMsg_ID,   constMsg_sender,  constMsg_receiver,   constMsg_text,   constMsg_send,   constMsg_received};
const std::vector <std::string> constMessagesTable_collumnTypes = { constMsgType_ID,   constMsgType_sender,  constMsgType_receiver,   constMsgType_text,   constMsgType_send,   constMsgType_received};










