#pragma once
#ifndef __STRING__
#define __STRING__
#include<string>
#endif
#ifndef __EMPLOYEE__
#define __EMPLOYEE__
struct Employed{
	std::string m_employeename;
	std::string m_number;
	Employed& operator=(const Employed& lhs)
	{
		m_employeename = lhs.m_employeename;
		m_number = lhs.m_number;
		return const_cast<Employed&>(lhs);
	}
};
#endif