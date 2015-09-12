#pragma once
#ifndef __STRING__
#define __STRING__
#endif 
#include<string>
#ifndef __SAVER__
#define __SAVER__
struct Saver{
	std::string m_account;
	std::string m_username;
	std::string m_password;
	std::string m_address;
	std::string m_savekind;
	std::string m_origalmoney;
	bool m_loss;
	std::string m_savetime;
	std::string m_losstime;
	Saver& operator= (const Saver& lhs)
	{
		m_account = lhs.m_account;
		m_username = lhs.m_username;
		m_password = lhs.m_password;
		m_address = lhs.m_address;
		m_savekind = lhs.m_savekind;
		m_origalmoney = lhs.m_origalmoney;
		m_loss = lhs.m_loss;
		m_savetime = lhs.m_savetime;
		m_losstime = lhs.m_losstime;
		return const_cast<Saver&>(lhs);
	}
};
#endif