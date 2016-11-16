/*
ID: hao.xu.1
PROG: barn1
LANG: C++
*/

#include<fstream>
#include<iostream>
#include<vector>

using namespace std;

void swap(int a[][2], int i, int j);

int require;
int farmer[5000][2];
int main_barn()
{
	ifstream fin("Section1.3/barn1.in");
	ofstream fout("Section1.3/barn1.out");
	//ifstream fin("barn1.in");
	//ofstream fout("barn1.out");
	fin >> require;
	int farmer_num;
	fin >> farmer_num;
	for (int i = 0; i < farmer_num; i++)
	{
		fin >> farmer[i][0];
		fin >> farmer[i][1];
	}

	int total_unit = 0;
	int total_money = 0;
	for (int i = 0; i < farmer_num; i++)
	{
		int min = i;
		for (int j = i + 1; j < farmer_num; j++)
		{
			if (farmer[j][0] < farmer[min][0])
				min = j;
		}
		if (total_unit < require) {
			int need = farmer[min][1] < (require- total_unit) ? farmer[min][1] : require - total_unit;
			total_unit += need;
			total_money += need*farmer[min][0];
		}
			swap(farmer, min, i);
	}
	fout << total_money << endl;
	return 0;
}

void swap(int a[][2],int i,int j)
{
	int one, two;
	one = a[i][0];       two = a[i][1];
	a[i][0] = a[j][0];   a[i][1] = a[j][1];
	a[j][0] = one;       a[j][1] = two;
}
