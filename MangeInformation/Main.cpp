
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
	std::cout << "����������������������������������������------" << std::endl;
	std::cout << "|         ��¼���й���ϵͳ                    |" << std::endl;
	std::cout << "|									            |" << std::endl;
    std::cout << "|  1-���    2 - ȡ��     3-��ʧ  4-���ֽ�    | " << std::endl;
	std::cout << "|            5-����¼                       |" << std::endl;
	std::cout << "|            6-ȡ���¼                       |" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	unsigned t;
	std::cout << "Waiting -----------������������������������������������" << std::endl;
	std::cout << "����������ѡ��" << std::endl;
	while (std::cin >> t){
		if (t < 7 && t > 0)
			break;
		std::cout << "��������ȷ��ѡ��" << std::endl;
	}
	std::string curStr;
	switch (t){
	case 1:{
			   std::cout << "���ڰ�����ҵ��" << std::endl;
			   std::cout << "����������˻�" << std::endl;
			   std::cin >> curStr;
			   m_S.m_account = curStr;
			   curStr.clear();

			   std::cout << "����������û���" << std::endl;
			   std::cin >> curStr;
			   m_S.m_username = curStr;
			   curStr.clear();

			   std::cout << "�������������" << std::endl;
			   std::cin >> curStr;
			   m_S.m_password = curStr;
			   curStr.clear();

			   std::cout << "��������ĵ�ַ" << std::endl;
			   std::cin >> curStr;
			   m_S.m_address = curStr;
			   curStr.clear();

			   std::cout << "��������" << std::endl;
			   while (std::cin >> curStr)
			   {
				   if (curStr == "1" || curStr == "2" || curStr == "3" || curStr == "5")
				   {
					   break;
				   }
				   std::cout << "���� 1 2  3  5֮��ѡ��" << std::endl;
			   }
			   m_S.m_savekind = curStr;
			   curStr.clear();

			   std::cout << "����" << std::endl;
			   std::cin >> curStr;
			   m_S.m_origalmoney = curStr;
			   curStr.clear();

			   std::cout << "�Ƿ�ʧ�����дTRUE ����������FALSE����" << std::endl;
			   std::cin >> curStr;
			   if (curStr == "TRUE")m_S.m_loss = true;
			   else m_S.m_loss = false;
			   curStr.clear();



			   time_t t = time(NULL);
			   timeToString(t, curStr);
			   m_S.m_savetime = curStr;
			   curStr.clear();

			   m_S.m_losstime = "";

			   std::cout << "��дӪҵԱ��Ϣ��д��ӪҵԱ������" << std::endl;
			   std::cin >> curStr;
			   m_E.m_employeename = curStr;
			   curStr.clear();

			   std::cout << "��дӪҵԱ��Ϣ��д��ӪҵԱ�Ĺ���" << std::endl;
			   std::cin >> curStr;
			   m_E.m_number = curStr;
			   curStr.clear();


			   Save save;
			   save.m_fSave(m_S, m_E);
			   std::cout << "������Ϣ�Ѿ����桪������������������������������" << std::endl;

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
			   std::cout << "���ڰ���ȡ��ҵ��" << std::endl;
			   WithDraw withdraw;
			   std::string curStr;
			   std::cout << "����������˻�" << std::endl;
			   std::cin >> curStr;
			   m_S.m_account = curStr;
			   curStr.clear();

			   std::cout << "����������û���" << std::endl;
			   std::cin >> curStr;
			   m_S.m_username = curStr;
			   curStr.clear();

			   std::cout << "�������������" << std::endl;
			   std::cin >> curStr;
			   m_S.m_password = curStr;
			   curStr.clear();


			   std::cout << "�������������� 1�� 2�� 3�� 5��" << std::endl;
			   while (std::cin >> curStr)
			   {
				   if (curStr == "1" || curStr == "2" || curStr == "3" || curStr == "5")
					   break;
				   std::cout << "������������1 2 3 5 ֮��ѡ��" << std::endl;
			   }
			   m_S.m_savekind = curStr;
			   curStr.clear();

			   std::cout << "����" << std::endl;
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
			   std::cout << "��������ʧҵ��" << std::endl;
			   Loss loss;
			   Saver m_sv;
			   std::string curStr;

			   std::cout << "����������˻�" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_account = curStr;
			   curStr.clear();


			   std::cout << "����������û���" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_username = curStr;
			   curStr.clear();

			   std::cout << "�������������" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_password = curStr;
			   curStr.clear();


			   std::cout << "�������� ����1 2 3 5 ֮��ѡ��" << std::endl;
			   while (std::cin >> curStr)
			   {

				   if (curStr == "1" || curStr == "2" || curStr == "3" || curStr == "5")
					   break;
				   std::cout << "�������� ����1 2 3 5 ֮��ѡ��" << std::endl;
			   }
			   m_sv.m_savekind = curStr;
			   curStr.clear();

			   std::cout << "����" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_origalmoney = curStr;
			   curStr.clear();

			   std::cout << "��ַ" << std::endl;
			   std::cin >> curStr;
			   m_sv.m_address = curStr;
			   m_sv.m_loss = false;
			   curStr.clear();

			   loss.m_fGetInformation(m_sv);
			   loss.m_fLoss();



	}break;

	case 4:

	{
			  std::cout << "�����������쵽����Ŀ" << std::endl;
			  long double llSum = 0;
			  TotalMoney to;
			  llSum = to.m_fToTalMoney();
			  std::cout << "�������е���һ��" << llSum << "Ԫ" << std::endl;
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
			   std::cout << "����1 2 3 4��ѡ����ѡ��" << std::endl;
			   goto start;
	}break;
	}
	goto start;
	return 0;
}