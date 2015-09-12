#pragma once
#include"Saver.h"
#include"Employed.h"
#ifndef __LIST__
#define __LIST__

#include<list>
#endif
#ifndef __LOSS__
#define __LOSS__
class Loss{


private:
	Saver m_Saver;
	Employed m_Employed;
	std::list<Saver> l_saver;
	std::list<Employed> l_employed;
public:
	bool m_fIsWithDraw();
	void m_fGetInformation(const Saver& save)
	{
		m_Saver = save;
	}
	void m_fLoss();
};
#endif