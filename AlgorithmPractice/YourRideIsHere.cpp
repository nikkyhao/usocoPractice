/*
ID: hao.xu.1
PROG: ride
LANG: C++             
*/

#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int letter2int(char c);
int getTotalNum(char c[]);
int main1()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	
	char comet_name[7];
	char group_name[7];

	fin >> comet_name;
	fin >> group_name;
	
	int comet_num = getTotalNum(comet_name);
	int group_num = getTotalNum(group_name);

	if (abs(comet_num - group_num) % 47 == 0)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;
	return 0;
}

int letter2int(char c)
{
	return ((int)c)-64;
}

int getTotalNum(char c[])
{
	int result = 1;
	for (int i = 0; i < strlen(c); i++)
	{
		result = result *letter2int(c[i]);
	}
	return result;
	
}