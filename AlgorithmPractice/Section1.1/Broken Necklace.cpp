/*
ID: hao.xu.1
PROG: beads
LANG: C++
*/
#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<map>

int my_max(int a, int b);

using namespace std;
char beads[710];

int main_beads()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int num; fin >> num;
	fin >> beads;
	for (int i = 0; i < num; i++)
	{
		beads[num + i] = beads[i];
	}
	int lb[710], lr[710], rb[710], rr[710];//lb[i]指的是第i个左边是连续蓝色的个数（包括第i个）
										//rb[i]指的是第i个右边连续蓝色的个数（包括第i个）
	//先处理左边
	lb[0] = 0; lr[0] = 0;
	for (int i = 1; i <= 2 * num - 1; i++)
	{
		if (beads[i] == 'b') { lb[i] = lb[i - 1] + 1; lr[i] = 0; }
		if (beads[i] == 'r') { lr[i] = lr[i - 1] + 1; lb[i] = 0; }
		if (beads[i] == 'w') { lb[i] = lb[i - 1] + 1; lr[i] = lr[i - 1] + 1; }
	}
	rb[num * 2 - 1] = 0; rr[num * 2 - 1] = 0;
	for (int i = num * 2 - 2; i >= 0; i--)
	{
		if (beads[i] == 'b') {
			rb[i] = rb[i + 1] + 1; rr[i] = 0;
		}
		if (beads[i] == 'r') {
			rr[i] = rr[i + 1] + 1; rb[i] = 0;
		}
		if (beads[i] == 'w') { rb[i] = rb[i + 1] + 1; rr[i] = rr[i + 1] + 1; }
	}

	int max = my_max(lb[0], lr[0]) + my_max(rb[1], rr[1]);
	for (int i = 1; i <= num * 2 - 2; i++)
	{
		int temp = my_max(lb[i], lr[i]) + my_max(rb[i+1], rr[i+1]);
			if (temp > max) max = temp;
	}
	if (max > num) max = num;
	fout << max<<endl;
	return 0;
}

int my_max(int a, int b) {
	if (a > b) return a;
	else return b;
}
