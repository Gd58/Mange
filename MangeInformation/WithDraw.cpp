#include"WithDraw.h"

#include<iomanip>
#ifndef __FSTREAM__
#define __FSTREAM__
#include"fstream"
#endif
#ifndef __IOSTREAM__
#define __IOSTREAM__
#include<iostream>
#endif
#ifndef __SSTREAM__
#define __SSTREAM__
#include<sstream>
#endif
#ifndef __TIME_T__
#define __TIME_T__
#include<time.h>
#endif
typedef struct {
	int iYear;
	int iMonth;
	int iDay;

}Date;

void stringToDate(const std::string& str,Date& date){
	char *pBeginPos = (char*)str.c_str();
	char *pPos = strstr(pBeginPos, "-");
	int iYear = atoi(pBeginPos);
	int iMonth = atoi(pPos + 1);

	pPos = strstr(pPos + 1, "-");

	int iDay = atoi(pPos + 1);
	date.iYear = iYear;
	date.iMonth = iMonth;
	date.iDay = iDay;

}
inline int GetSaveTime(const std::string& str)
{
	return atoi(const_cast<char*>(str.c_str()));
}
void timeToString(const time_t& time, std::string& str)
{
	tm tm1;
	localtime_s(&tm1, &time);
	char c_time[15];
	sprintf_s(c_time, "%2d-%1d-%2d", tm1.tm_year + 1900, tm1.tm_mon + 1, tm1.tm_mday);
	std::string str_(c_time);
	str = str_;

}
/*
void stringToTime(time_t& time, const char* szTime)
{
	
	time_t time1;
	char*pBeginPos = const_cast<char*>(szTime);
	char *pPos = strstr(pBeginPos, "-");
	
	int iYear = atoi(pBeginPos);
	int iMonth = atoi(pPos + 1);
	pPos = strstr(pPos + 1, "-");
	int iDay = atoi(pPos);
	tm tm1;
	tm1.tm_mday = iDay;
	tm1.tm_mon = iMonth;
	tm1.tm_year = iYear;
	time = mktime(&tm1);
}
*/
int stringToTime(time_t &timeData, const std::string &strDateStr)
{
	char *pBeginPos = (char*)strDateStr.c_str();
	char *pPos = strstr(pBeginPos, "-");
	if (pPos == NULL)
	{
		return -1;
	}
	int iYear = atoi(pBeginPos);
	int iMonth = atoi(pPos + 1);

	pPos = strstr(pPos + 1, "-");
	if (pPos == NULL)
	{
		return -1;
	}

	int iDay = atoi(pPos + 1);

	struct tm sourcedate;
	memset((void*)&sourcedate, 0, sizeof(sourcedate));
	sourcedate.tm_mday = iDay;
	sourcedate.tm_mon = iMonth - 1;
	sourcedate.tm_year = iYear - 1900;


	timeData = mktime(&sourcedate);

	return 0;
}
bool lessTime(const time_t& t1, const time_t& t2,int x)
{
	tm tm1;
	localtime_s(&tm1, &t1);
	tm tm2;
	localtime_s(&tm2, &t2);
	if (tm1.tm_year > (tm2.tm_year+x))
		return true;
	else if (tm1.tm_year < (tm2.tm_year+x))
		return false;
	else
	{
		if (tm1.tm_mon > tm2.tm_mon)
			return true;
		else if (tm1.tm_mon < tm2.tm_mon)
		{
			return false;
		}
		else
		{
			if (tm1.tm_mday > tm2.tm_mday)
				return true;
			else
				return false;
		}
	}
}
int WithDraw::m_fAbleTo(){
	  
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
	Iter pBegin = l_saver.begin();
	std::list<Employed>::iterator EIter = l_employed.begin();
	for (auto t : l_saver){
		if (m_Saver.m_account == t.m_account&&
			m_Saver.m_username == t.m_username&&
			m_Saver.m_savekind == t.m_savekind&&
			m_Saver.m_origalmoney == t.m_origalmoney){
			time_t t2 = time(NULL);
			time_t curTime;
			stringToTime(curTime,m_Saver.m_savetime);
			int x = GetSaveTime(m_Saver.m_savekind);
			if (!lessTime(t2,curTime, x))//表示还没有到期
			{
				std::cout << "您的账户还没有到期" << std::endl;
				//
				std::cout << "请再次输入密码" << std::endl;
				std::string curStr_;
				std::cin >> curStr_;
				if (curStr_ == m_Saver.m_password)
				{
					m_curIter = pBegin;
					std::cout << "密码输入正确" << std::endl;
					//这里需要添加信息
					m_exist = true;
					m_Saver.m_losstime = t.m_losstime;
					t.m_loss ? m_Saver.m_loss = true : m_Saver.m_loss = false;
					m_Saver.m_address = t.m_address;
					m_Employed.m_employeename = EIter->m_employeename;
					m_Employed.m_number = EIter->m_number;
					
					return 1;
				}
				else
				{
					std::cout << "密码错误" << std::endl;

					m_exist = false;
					return 0;
				}
			}
			else{
					if (m_Saver.m_loss)
					{
						std::cout << "您的账户已经挂失" << std::endl;
						m_exist = false;
						return false;
					}
					else
					{
						std::cout << "请再次输入密码" << std::endl;
						std::string curStr_;
						std::cin >> curStr_;
						if (curStr_ == m_Saver.m_password)
						{
							m_curIter = pBegin;
							std::cout << "密码输入正确"<<std::endl;
							//这里需要添加信息
							m_exist = true;
							m_Saver.m_losstime = t.m_losstime;
							t.m_loss ? m_Saver.m_loss = true : m_Saver.m_loss = false;
							m_Saver.m_address = t.m_address;
							m_Employed.m_employeename = EIter->m_employeename;
							m_Employed.m_number = EIter->m_number;
							return 1;
						}
						else
						{
							std::cout << "密码错误" << std::endl;
							
							m_exist = false;
							return 0;
						}
					}
			}

			++pBegin;
			++EIter;
			
		}
	}
	m_exist = false;
	std::cout << "数据库中没有您的信息" << std::endl;
	return -1;


}
bool WithDraw::m_fChangeInformation(){
	std::list<Saver>::iterator Iter = m_curIter;
	l_saver.erase(Iter);
	std::fstream write;
	write.open("SaveEmployedSaver.txt", std::ios::out);
	std::list<Saver>::iterator it = l_saver.begin();

	if (write){
		if (it == l_saver.end())
			return true;
		else
		{
			++it;
		if (it == l_saver.end())
		{
			std::list<Saver>::iterator iter = l_saver.begin();
			write << iter->m_account << " " << iter->m_username << " " << iter->m_password << " " << iter->m_address << " "
				<< iter->m_savekind << " " << iter->m_origalmoney << " " << iter->m_loss << " " << iter->m_savetime << " " << iter->m_losstime << '\n';

		}
		else{
						auto t = l_saver.begin();
						auto s = --l_saver.end();
						for (; t != s; ++t){
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
		
						
						write << t->m_account<<" "<<t->m_username<<" "<<t->m_password<<" "<<t->m_address<<" "
							<<t->m_savekind<<" "<<t->m_origalmoney<<" "<<t->m_loss<<" "<<t->m_savetime<<" "<<t->m_losstime<<'\n';
	
					}
		
		}
		}
	write.close();
	}
	return true;

	
}

void WithDraw::m_fAddInformation()
{
	if (m_exist == false)
		std::cout << "不存在您的信息" << std::endl;
	else
	{
		std::fstream write;
		write.open("WithDrawEmployedSaver.txt", std::ios::app);
		
		write << m_Saver.m_account << " " << m_Saver.m_username << " "
			<< m_Saver.m_password << " " << m_Saver.m_address << " "
			<< m_Saver.m_savekind << " " << m_Saver.m_origalmoney << " "
			<< m_Saver.m_loss << " " << m_Saver.m_savetime << " " << m_Saver.m_losstime <<" "<< m_Employed.m_employeename << " " << m_Employed.m_number << "\n";
		write.close();
		
	}
}
/*
int sum(int y, int m, int d){
	int md[13] = { 0, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30 };
	int cnt = y * 365;
	cnt += (y - 1) / 4 + 1;
	cnt -= (y - 1) / 100 + 1;
	cnt += (y - 1) / 400 + 1;
	for (int i = 1; i < m; ++i) cnt += md[i];
	if (m > 2) ++cnt;
	cnt += d;
	return cnt;
}
int Count(int y1, int m1, int d1, int y2, int m2, int d2){
	return sum(y2, m2, d2) - sum(y1, m1, d1);
}
*/

long long diffDate(int iYearl, int iMonthl, int iDayl, int iYearr, int iMonthr, int iDayr){
	long long  iCount = 0;
	if (iYearl > iYearr){
		if (iYearl - iYearr == 1){
			iCount = (12 - iMonthl + iMonthr - 1) * 30 + 30 - iDayl + iDayr;
		}
		else{
			int iMid = iYearl - iYearr - 1;
			iCount = (12 - iMonthl + iMonthr - 1) * 30 + 30 - iDayl + iDayr + iMid * 360;
		}
		return iCount;
	}
	else if (iYearl == iYearr){
		return (iMonthl - iMonthr - 1) * 30 + 30 - iDayl + iDayr;
	}
	else
		return -1;
}
bool WithDraw::m_fWithDraw(){
	time_t todayTime = time(NULL);
	std::string todayStr;
	timeToString(todayTime, todayStr);
	time_t SaveTime;
	//tm SaveTm;
	stringToTime(SaveTime, m_Saver.m_savetime);
	long long llCount = 0;
	Date SaveDate, todayDate;
	stringToDate(m_Saver.m_savetime, SaveDate);
	stringToDate(todayStr, todayDate);
	/////////////////////
	//////////
	////////////
	//localtime_s(&todayTm, &todayTime);
	int b_cur = m_fAbleTo();
	if (m_exist){
		if (m_Saver.m_loss == false){
					if (b_cur == 1){
								llCount = diffDate(todayDate.iYear, todayDate.iMonth, todayDate.iDay,
									SaveDate.iYear + GetSaveTime(m_Saver.m_savekind), SaveDate.iMonth, SaveDate.iDay);
								int curValue = GetSaveTime(m_Saver.m_savekind);
									switch (curValue){
									case 1:m_insterest = atof(m_Saver.m_origalmoney.c_str()) * 1 * 0.0198; break;
									case 2:m_insterest = atof(m_Saver.m_origalmoney.c_str()) * 2 * 0.0225; break;
									case 3:m_insterest = atof(m_Saver.m_origalmoney.c_str()) * 3 * 0.0252; break;
									default:m_insterest = atof(m_Saver.m_origalmoney.c_str()) * 2 * 0.0279; break;
									}

								m_insterest += llCount * 0.0002;
								m_origal_inst = atof(m_Saver.m_origalmoney.c_str()) + m_insterest * 0.8;
								m_fChangeInformation();
								m_fAddInformation();
								m_fPrint();
								std::cout << "取款成功" << std::endl;
								return true;
							
					}


					
					else if (b_cur == 0){
						llCount = diffDate(todayDate.iYear, todayDate.iMonth, todayDate.iDay,
							SaveDate.iYear, SaveDate.iMonth, SaveDate.iDay);

						m_insterest = atof(m_Saver.m_origalmoney.c_str()) * llCount * 0.00002;
						m_origal_inst = atof(m_Saver.m_origalmoney.c_str()) + m_insterest * 0.8;
						m_fChangeInformation();
						m_fAddInformation();
						m_fPrint();
						std::cout << "取款成功" << std::endl;
						return true;
					}
					else
						std::cout << "您的账户不存在" << std::endl;
			
		}
		else{
			std::cout << "您的账户已挂失不能取款" << std::endl;
		}
	}
	else{
		std::cout << "您的账户不存在" << std::endl;
		
	}
	return false;
}

void WithDraw::m_fPrint(){

	/*
	打印利息单，其内容包括：账号、姓名、储种、起息日期、
	支取日期、本金、利息和支取金额
	*/
	time_t t = time(NULL);
	std::string str;
	timeToString(t, str);
	std::cout << std::setw(10) << "账号" << std::setw(10) << "姓名" << std::setw(10) << "储种" << std::setw(10) << "起息日期" << std::setw(10)
		<< std::setw(10) << "支取日期" << std::setw(10) << "本金" << std::setw(10) << "利息" << std::setw(10) << "支取金额" << std::endl;

	std::cout<<std::endl;

	std::cout << std::setw(10) << m_Saver.m_account << std::setw(10) << m_Saver.m_username << std::setw(10) << m_Saver.m_savekind << std::setw(10) << m_Saver.m_savetime << std::setw(10)
		<< std::setw(10) << str << std::setw(10) << m_Saver.m_origalmoney<< std::setw(10) << m_insterest << std::setw(10) << m_origal_inst << std::endl;
		
}