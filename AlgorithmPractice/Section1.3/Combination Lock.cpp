/*
ID: hao.xu.1
PROG: combo
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>

using namespace std;
int distance(int a, int b, int num);


int main_combo()
{
	//ifstream fin("Section1.3/combo.in");
	//ofstream fout("Section1.3/combo.out");
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	int d = 5;
	int num;
	fin >> num;
	if (num < 5)
	{
		fout << num*num*num << endl;
		return 0;
	}
	int a[3], b[3];
	for (int i = 0; i < 3; i++) 
		fin >> a[i];
	for (int i = 0; i < 3; i++) 
		fin >> b[i];

	int intersection[3];
	for (int i = 0; i < 3; i++)
		intersection[i] = d-distance(a[i], b[i], num);

	for (int i = 0; i < 3; i++)
	{
		if (intersection[i] < 0) intersection[i] = 0;
	}

	int inters_num = 1;
	for (int i = 0; i < 3; i++)
		inters_num = inters_num*(intersection[i]);

	fout << 2*d*d*d - inters_num << endl;


	
	return 0;
}

//这个方法太二笔了，以后改改。。
int distance(int a, int b, int num)
{
	int m, n;
	if (a > b) {
		m =(a - b) % num;
		n = (b - a) % num + num;
	}else {
		m = (b - a) % num;
		n = (a - b) % num + num;
	}
	return m > n ? n : m;
}

