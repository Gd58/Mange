
#include"Save.h"
#ifndef __FSTREAM__
#define __FSTREAM__
#include<fstream>
#endif
void Save::m_fSave(const Saver& lhs,const Employed& rhs){
	/*
	std::string m_acount;
	std::string m_username;
	std::string m_password;
	std::string m_address;
	unsigned m_savekind;
	long long m_origalmoney;
	bool m_loss;
	time_t m_savetime;
	time_t m_losstime;
	*/
	std::fstream write("SaveEmployedSaver.txt",std::ios::app);
	write << lhs.m_account << " " << lhs.m_username << " "
		<< lhs.m_password << " " << lhs.m_address << " "
		<< lhs.m_savekind << " " << lhs.m_origalmoney << " "
		<< lhs.m_loss << " " << lhs.m_savetime << " " << lhs.m_losstime << rhs.m_employeename << " " << rhs.m_number <<"\n";
	write.close();
}