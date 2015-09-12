#include"SaveView.h"
#include"Saver.h"
#include"Employed.h"
#ifndef __FSTREAM__
#define __FSTREAM__
#include<fstream>
#ifndef __IOSTREAM__
#define __IOSTREAM__
#include<iostream>
#endif
#endif
#ifndef __STRING__
#define __STRING__
#include<string>
#endif
#ifndef __SSTREAM__
#define __SSTREAM__
#include<sstream>
#endif
#ifndef __LIST__
#define __LIST__
#include<list>
#endif
#ifndef __IOMANIP__
#define __IOMANIP__
#include<iomanip>
#endif
void SaveView::view()
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
	while (!Read.eof())
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
	std::list<Employed>::iterator Iter = l_employed.begin();
	std::cout << std::setw(10) << "账号" << std::setw(10) << "姓名" << std::setw(10) << "储种" << std::setw(10) << "起息日期" << std::setw(10)
		<< std::setw(10) << "存取金额" <<std::endl;

	std::cout << std::endl;
	for (auto m_Saver : l_saver)
	{
		

		std::cout << std::setw(10) << m_Saver.m_account << std::setw(10) << m_Saver.m_username << std::setw(10) << m_Saver.m_savekind << std::setw(10) << m_Saver.m_savetime << std::setw(10)
			<< std::setw(10) << m_Saver.m_origalmoney << std::endl;
		++Iter;
	}
}