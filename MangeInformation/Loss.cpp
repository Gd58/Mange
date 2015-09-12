#include"loss.h"
#ifndef __SSTREAM__
#define __SSTREAM__
#include<sstream>
#endif 
#ifndef __FSTREAM__
#define __FSTREAM__
#include<fstream>
#endif
#ifndef __IOSTREAM__
#define __IOSTREAM__
#include<iostream>
#endif
bool Loss::m_fIsWithDraw(){
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
	bool b_cur = false;
	auto t3 = l_Saver.begin();
	for (; t3!= l_Saver.end();++t3){
		//账号、姓名、密码、地址、储种和储金
		if (m_Saver.m_account == t3->m_account&&
			m_Saver.m_username == t3->m_username&&
			m_Saver.m_savekind == t3->m_savekind&&
			m_Saver.m_origalmoney == t3->m_origalmoney&&
			m_Saver.m_password == t3->m_password&&
			m_Saver.m_address == t3->m_address){
			b_cur = true;
			break;
		}
		++iter;
	}
	return b_cur;

}
void Loss::m_fLoss(){
	std::string curStr;


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
	typedef std::list<Saver>::iterator Iter;
	bool b_able = false;
	auto t = l_saver.begin();
	for (; t != l_saver.end();++t){
		//账号、姓名、密码、地址、储种和储金
		if (m_Saver.m_account == t->m_account&&
			m_Saver.m_username == t->m_username&&
			m_Saver.m_savekind == t->m_savekind&&
			m_Saver.m_origalmoney == t->m_origalmoney&&
			m_Saver.m_password == t->m_password&&
			m_Saver.m_address == t->m_address){
			t->m_loss = true;
			b_able = true;
			break;
		}
	}
	if (b_able){
		std::fstream write;
		write.open("SaveEmployedSaver.txt", std::ios::out);
		Iter iter = l_saver.begin();
		std::list<Employed>::iterator Ei = l_employed.begin();
		Iter end = l_saver.end();
		--end;
		while (iter != end){
			write << iter->m_account << " " << iter->m_username << " "
				<< iter->m_password << " " << iter->m_address << " "
				<< iter->m_savekind << " " << iter->m_origalmoney << " "
				<< iter->m_loss << " " << iter->m_savetime << " " << iter->m_losstime << " " << Ei->m_employeename << " " << Ei->m_number << "\n";
			++iter;
			++Ei;
		}
		write.close();
		std::cout << "挂失成功" << std::endl;
		return;
	}
	else{
			if (m_fIsWithDraw())
			{
				std::cout << "最近您有取过" << std::endl;
			}
			else
			std::cout << "不存在您的账户 挂失失败" << std::endl;
	}
	return;
}