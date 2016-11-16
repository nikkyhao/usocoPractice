/*
ID: hao.xu.1
PROG: palsquare
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

char letterss[20] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };
class BaseNum {
public:
	BaseNum(int _base) { base = _base; number = 0; length = get_length(); }
	BaseNum(int _base, int num) { base = _base; number = num; length = get_length(); }
	inline void set_number(int num) { number = num;  length = get_length();}
	bool isPal()//是否回文
	{
		for (int i = 0; i < length; i++)
		{
			if (get(i) != get(length - i - 1)) return false;
		}
		return true;
	}
	char get(int i) {//目前是从右往左
		if (i == 0) return letterss[number % base];
		else {
			return letterss[(number / (int)pow(base, i)) % base];
		}
	}
	void square() { number = number *number; length = get_length();}
	void toString(ofstream& fout)
	{
		int num = number;
		int i = 0;
		while (i<length) {
			fout << get(length - i - 1);
			i++;
		}
	}
	void plus() { number++; }
private:
	int base;
	int number;
	int length;//相应进制的长度
	
	int get_length() {
		int _length = 0;
		while (number / (int)pow(base, _length))
			_length++;
		return _length;
	}
};

int base;
int main_palsquare()
{
	ifstream fin("Section1.2/palsquare.in");
	ofstream fout("Section1.2/palsquare.out");
	//ifstream fin("palsquare.in");
	//ofstream fout("palsquare.out");
	fin >> base;
	BaseNum num(base, 1);
	BaseNum num2(base, 1);
	for (int i = 1; i <= 300; i++)
	{
		num.set_number(i);
		num.square();
		if (num.isPal()) {
			num2.set_number(i);
			num2.toString(fout); fout << " ";
			num.toString(fout); fout << endl;
		}
	}
	return 0;
}

