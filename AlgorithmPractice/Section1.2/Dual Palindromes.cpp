/*
ID: hao.xu.1
PROG: dualpal
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

char letters[20] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };
class BaseNum {
public:
	BaseNum(int _base) { base = _base; number = 0; length = get_length(); }
	BaseNum(int _base, int num) { base = _base; number = num; length = get_length(); }
	inline void set_number(int num) { number = num;  length = get_length(); }
	inline void set_base(int _base) { base = _base;  length = get_length(); }
	bool isPal()//是否回文
	{
		for (int i = 0; i < length; i++)
		{
			if (get(i) != get(length - i - 1)) return false;
		}
		return true;
	}
	char get(int i) {//目前是从右往左
		if (i == 0) return letters[number % base];
		else {
			return letters[(number / (int)pow(base, i)) % base];
		}
	}
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
	int get_number() { return number; }
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

int main_dualpal()
{
	//ifstream fin("Section1.2/dualpal.in");
	//ofstream fout("Section1.2/dualpal.out");
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int N, S;
	fin >> N >> S;
	int num = 0;
	int match_num = 0;
	BaseNum basenum(2,S+1);
	while (num<N)
	{
		for (int i = 2; i <= 10; i++)
		{
			basenum.set_base(i);
			if (basenum.isPal())
			{
				match_num++;
				if (match_num == 2) {
					num++;
					fout << basenum.get_number() << endl;
					break;
				}
			}
		}
		match_num = 0;
		basenum.plus();
	}
	return 0;
}

