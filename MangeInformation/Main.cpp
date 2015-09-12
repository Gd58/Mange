
#include"WithDraw.h"
#include"Save.h"
#include"Loss.h"
#include"TotalMoney.h"
#include"SaveView.h"
#include"WithDrawView.h"

#ifndef __TIME_T__
#define __TIME_T
#include<time.h>
#endif
#ifndef __IOSTREAM__
#define __IOSTREAM__
#include<iostream>
#endif
extern void timeToString(const time_t& time, std::string& str);
int main()
  {
start:
	Employed m_E;
	Saver m_S;
	std::cout << "————————————————————------" << std::endl;
	std::cout << "|         登录银行管理系统                    |" << std::endl;
	std::cout << "|									            |" << std::endl;
    std::cout << "|  1-存款    2 - 取款     3-挂失  4-总现金    | " << std::endl;
	std::cout << "|            5-存款记录                       |" << std::endl;
	std::cout << "|            6-取款记录                       |" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	unsigned t;
	std::cout << "Waiting -----------——————————————————" << std::endl;
	std::cout << "请输入您的选择" << std::endl;
	while (std::cin >> t){
		if (t < 7 && t > 0)
			break;
		std::cout << "请输入正确的选择" << std::endl;
	}
	std::string curStr;
	switch (t){
	case 1:{
			   std::cout << "现在办理存款业务" << std::endl;
			   std::cout << "请输入你的账户" << std::endl;
			   std::cin >> curStr;
			   m_S.m_account = curStr;
			   curStr.clear();

			   std::cout << "请输入你的用户名" << std::endl;
			   std::cin >> curStr;
			   m_S.m_username = curStr;
			   curStr.clear();

			   std::cout << "请输入你的密码" << std::endl;
			   std::cin >> curStr;
			   m_S.m_password = curStr;
			   curStr.clear();

			   std::cout << "请输入你的地址" << std::endl;
			   std::cin >> curStr;
			   m_S.m_address = curStr;
			   curStr.clear();

			   std::cout << "储蓄种类" << std::endl;
			   while (std::cin >> curStr)
			   {
				   if (curStr == "1" || curStr == "2" || curStr == "3" || curStr == "5")
				   {
					   break;
				   }
				   std::cout << "请在 1 2  3  5之间选择" << std::endl;
			   }
			   m_S.m_savekind = curStr;
			   curStr.clear();

			   std::cout << "本金" << std::endl;
			   std::cin >> curStr;
			   m_S.m_origalmoney = curStr;
			   curStr.clear();

			   std::cout << "是否丢失如果是写TRUE 其他都按照FALSE处理" << std::endl;
			   std::cin >> curStr;
			   if (curStr == "TRUE")m_S.m_loss = true;
			   else m_S.m_loss = false;
			   curStr.clear();



			   time_t t = time(NULL);
			   timeToString(t, curStr);
			   m_S.m_savetime = curStr;
			   curStr.clear();

			   m_S.m_losstime = "";

			   std::cout << "填写营业员信息，写入营业员的名字" << std::endl;
			   std::cin >> curStr;
			   m_E.m_employeename = curStr;
			   curStr.clear();

			   std::cout << "填写营业员信息，写入营业员的工号" << std::endl;
			   std::cin >> curStr;
			   m_E.m_number = curStr;
			   curStr.clear();


			   Save save;
			   save.m_fSave(m_S, m_E);
			   std::cout << "您的信息已经保存————————————————" << std::endl;

	}break;
		/*
		std::string;
		std::string m_account;
		std::string m_username;
		std::string m_password;
		std::string m_address;
		std::string m_savekind;
		std::string m_origalmoney;
		bool m_loss;
		std::string m_savetime;
		std::string m_losstime;*/

	case 2:{
			   std::cout << "现在办理取款业务" << std::endl;
			   WithDraw withdraw;
			   std::string curStr;
			   std::cout << "请输入你的账户" << std::endl;
			   std::cin >> curStr;
			   m_S.m_account = curStr;
			   curStr.clear();

			   std::cout << "请输入你的用户名" << std::endl;
			   std::cin >> curStr;
			   m_S.m_username = curStr;
			   curStr.clear();

			   std::cout << "请输入你的密码" << std::endl;
			   std::cin >> curStr;
			   m_S.m_password = curStr;
			   curStr.clear();


			   std::cout << "储蓄种类有四种 1年 2年 3年 5年" << std::endl;
			   while (std::cin >> curStr)
			   {
				   if (curStr == "1" || curStr == "2" || curStr == "3" || curStr == "5")
					   break;
				   std::cout << "储蓄种类请在1 2 3 5 之间选择" << std::endl;
			   }
			   m_S.m_savekind = curStr;
			   curStr.clear();

			   std::cout << "本金" << std::endl;
			   std::cin >> curStr;
			   m_S.m_origalmoney = curStr;
			   curStr.clear();

			   time_t t = time(NULL);
			   timeToString(t, curStr);
			   m_S.m_savetime = curStr;
			   curStr.clear();

			   m_S.m_loss = false;
			   m_S.m_losstime = "";
			   m_S.m_address = "";
			   withdraw.m_fGetInformation(m_S);
			   withdraw.m_fWithDraw();




	}break;
	case 3:{
			   std::cout << "这里办理挂失业务" << std::endl;
			   Loss loss;
			   Saver m_sv;
			   std::string curStr;

			   std::cout << "请输入你的账户" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_account = curStr;
			   curStr.clear();


			   std::cout << "请输入你的用户名" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_username = curStr;
			   curStr.clear();

			   std::cout << "请输入你的密码" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_password = curStr;
			   curStr.clear();


			   std::cout << "储蓄种类 请在1 2 3 5 之间选择" << std::endl;
			   while (std::cin >> curStr)
			   {

				   if (curStr == "1" || curStr == "2" || curStr == "3" || curStr == "5")
					   break;
				   std::cout << "储蓄种类 请在1 2 3 5 之间选择" << std::endl;
			   }
			   m_sv.m_savekind = curStr;
			   curStr.clear();

			   std::cout << "本金" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_origalmoney = curStr;
			   curStr.clear();

			   std::cout << "地址" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_address = curStr;
			   m_sv.m_loss = false;
			   curStr.clear();

			   loss.m_fGetInformation(m_sv);
			   loss.m_fLoss();



	}break;

	case 4:

	{
			  std::cout << "计算银行三天到账数目" << std::endl;
			  long double llSum = 0;
			  TotalMoney to;
			  llSum = to.m_fToTalMoney();
			  std::cout << "三天银行到账一共" << llSum << "元" << std::endl;
	}
		break;

	case 5:{
			   SaveView saveview;
			   saveview.view();

	}break;
	case 6:{
			   WithDrawView withdrawview;
			   withdrawview.view();

	}break;
	default:
	{
			   std::cout << "请在1 2 3 4个选项中选择" << std::endl;
			   goto start;
	}break;
	}
	goto start;
	return 0;
}