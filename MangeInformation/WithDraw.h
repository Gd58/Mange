#pragma once
#include"Saver.h"
#include"Employed.h"
#ifndef __LIST__
#define __LIST__
#include<list>
#endif
#ifndef __WITHDRAW__
#define __WITHDRAW__
class WithDraw{
public:
	void m_fGetInformation(const Saver&lhs)
	{
		m_Saver = std::move(lhs);
		m_exist = true;
	}
	int m_fAbleTo();
	void m_fAddInformation();
	bool m_fWithDraw();
	void m_fPrint();
	bool m_fChangeInformation();
private:
		typedef std::list<Saver>::iterator Iter;
		Iter m_curIter;
	    long double m_insterest;
		long double m_origal_inst;
		bool m_exist;
	    Saver m_Saver;
		Employed m_Employed;
		std::list<Saver> l_saver;
		std::list<Employed> l_employed;
};
#endif