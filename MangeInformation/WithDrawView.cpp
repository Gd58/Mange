#include"WithDrawView.h"
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

void WithDrawView::view(){
	std::string curStr;
	Saver curSaver;
	Employed curEmployed;
	std::list<Saver> l_Saver;
	std::list<Employed> l_Employed;

	std::fstream Read("WithDrawEmployedSaver.txt");
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

		l_Saver.push_back(curSaver);
		l_Employed.push_back(curEmployed);
	}
	Read.close();

	typedef std::list<Employed>::iterator EIter;
	EIter iter = l_Employed.begin();

	std::cout << std::setw(10) << "账号" << std::setw(10) << "姓名" << std::setw(10) << "储种" << std::setw(10) << "起息日期" << std::setw(10)
		<< std::setw(10) << "取走金额" << std::endl;

	std::cout << std::endl;
	for (auto m_Saver : l_Saver)
	{


		std::cout << std::setw(10) << m_Saver.m_account << std::setw(10) << m_Saver.m_username << std::setw(10) << m_Saver.m_savekind << std::setw(10) << m_Saver.m_savetime << std::setw(10)
			<< std::setw(10) << m_Saver.m_origalmoney << std::endl;
		++iter;
	}
}