/*
ID: hao.xu.1
PROG: friday	
LANG: C++
*/

#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<map>

using namespace std;

bool isLeapYear(int year);
int cal_days(int year, int month);

int n;//�ܹ�������
int yue_leap[] = {31,29,31,30,31,30,31,31,30,31,30,31 };
int yue[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int main()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	fin >> n;
	int week[7] = { 0 };//��������ʹ����ȫ����ʼ��Ϊ0
	for (int year = 0; year < n; year++)
	{
		for (int month = 0; month < 12; month++)
		{
			int days = cal_days(year, month);
			week[days % 7]++;
		}
	}
	fout << week[5]<<" ";
	fout << week[6] << " ";
	for (int i = 0; i < 4; i++)
		fout << week[i] <<" ";
	fout << week[4] << endl;

	return 0;
}

int cal_days(int year, int month)//year��month���Ǵ�0��ʼ��
{
	int days = 0;
	for (int i = 0; i < year; i++)
	{
		if (isLeapYear(i)) days += 366;
		else days += 365;
	}
	if (isLeapYear(year))
	{
		for (int i = 0; i < month; i++)
			days += yue_leap[i];
	}
	else
	{
		for (int i = 0; i < month; i++)
			days += yue[i];
	}
	days += 12;//13��
	return days;
}


bool isLeapYear(int year)//�����Ǵ�0��ʼ��
{
	int actual_year = 1900 + year;
	if ((actual_year % 100 == 0 && (actual_year % 400 == 0)) || !(actual_year % 100 == 0) && (actual_year % 4 == 0)) {
		return true;
	}
	return false;
}