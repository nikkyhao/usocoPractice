/*
ID: hao.xu.1
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<map>

using namespace std;


class People
{
public:
	int gift_money = 0;
	People() {};
	People(const string &name) {  this->name = name; }
	void getMoney(ofstream& fout) { fout << name<<" "<<total_money<<endl; }
	void giveMoney(int money, People *people) { 
		total_money -= money; 
		people->receive(money); }
private:
	int total_money = 0;
	string name;

	void receive(int _money) { total_money = total_money + _money; }
};

int main_gift1()
{
	ofstream fout("gift1.out"); 
	ifstream fin("gift1.in");
	int n = 0;//总人数
	fin >> n;
	People peoples[10];
	map<string, People*> my_map;
	fin.get();//用于消化换行符

	for (int i = 0; i < n; i++)
	{
		string name;
		getline(fin, name);
		peoples[i] = People(name);
		my_map.insert(map<string, People*>::value_type(name, &peoples[i]));
	}
	//开始送礼过程
	for (int i = 0; i < n; i++)
	{
		string name;
		int gift_money, lend_num;
		getline(fin, name);
		fin >> gift_money >> lend_num;
		fin.get();
		People* lender = my_map[name];
		lender->gift_money = gift_money;
		for(int i = 0;i<lend_num;i++)
		{
			string lend_to_name;
			getline(fin, lend_to_name);
			People* lend_to = my_map[lend_to_name];
			lender->giveMoney((lender->gift_money) / lend_num, lend_to);
		}
		if(lend_num!=0)
		lender->gift_money %= lend_num;
	}
	for (int i = 0; i < n; i++)
	{
		peoples[i].getMoney(fout);
	}
	return 0;
}

