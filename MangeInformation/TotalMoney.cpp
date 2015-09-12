#pragma once

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include<iostream>
#endif




#include"Saver.h"
#include"Employed.h"
#include"TotalMoney.h"
#include<algorithm>
#ifndef __SSTREAM__
#define __SSTREAM__
#include<sstream>
#endif
#ifndef __FSTREAM__
#define __FSTREAM__
#include<fstream>
#endif
#ifndef __TIME_T__
#define _TIME_T__
#include<time.h>
#endif
#ifndef __LIST__
#define __LIST__
#include<list>
#endif
	extern struct Date{
	int iYear;
	int iMonth;
	int iDay;
};

extern void stringToDate(const std::string& str, Date& date);
extern void timeToString(const time_t& time, std::string& str);
extern long long diffDate(int iYearl, int iMonthl, int iDayl, int iYearr, int iMonthr, int iDayr);



long double TotalMoney::m_fToTalMoney()
{
	std::string curStr;
	std::list<Saver> l_saver;
	std::list<Employed> l_employed;
	Saver curSaver;
	Employed curEmployed;
	std::fstream Read("SaveEmployedSaver.txt");
	/*
	std::string m_account;
	std::string m_username;
	std::string m_password;
	std::string m_address;
	std::string m_savekind;
	std::string m_origalmoney;
	bool m_loss;
	std::string m_savetime;
	std::string m_losstime;
	*/
	while (Read)
	{
		std::getline(Read, curStr);
		std::istringstream curBuf(curStr);
		std::string str;

		curBuf >> str;
		curSaver.m_account = str;
		str.clear();

		curBuf >> str;
		curSaver.m_username = str;
		str.clear();

		curBuf >> str;
		curSaver.m_password = str;
		str.clear();

		curBuf >> str;
		curSaver.m_address = str;
		str.clear();

		curBuf >> str;
		curSaver.m_savekind = str;
		str.clear();

		curBuf >> str;
		curSaver.m_origalmoney = str;
		str.clear();

		curBuf >> str;
		if (str == "1")
		{
			curSaver.m_loss = true;
		}
		else
			curSaver.m_loss = false;

		str.clear();

		curBuf >> str;
		curSaver.m_savetime = str;
		str.clear();

		curBuf >> str;
		curSaver.m_losstime = str;
		str.clear();

		curBuf >> str;
		curEmployed.m_employeename = str;
		str.clear();

		curBuf >> str;
		curEmployed.m_number = str;
		str.clear();
		l_saver.push_back(curSaver);
		l_employed.push_back(curEmployed);
	}
	Read.close();
	long double Sum = 0;
	std::list<Saver>::iterator Iter = l_saver.begin();
	std::list<Saver>::iterator end = l_saver.end();
	--end;
	for (; Iter != end; ++Iter){
		time_t t1 = time(NULL);
		std::string toStr;
		timeToString(t1,toStr);
		Date toDate,savDate;


		stringToDate(toStr,toDate);
		

		stringToDate(Iter->m_savetime, savDate);
		if (diffDate(toDate.iYear, toDate.iMonth, toDate.iDay, savDate.iYear, savDate.iMonth, savDate.iDay) <= 3)
		{
			
			Sum += atof(const_cast<char*>(Iter->m_origalmoney.c_str()));
		}


			}
	return Sum;
}