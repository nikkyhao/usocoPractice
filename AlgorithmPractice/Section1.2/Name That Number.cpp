/*
ID: hao.xu.1
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>




class Ternary {
public:
	Ternary() { number = 0; }
	Ternary(int num) { number = num; }
	int get(int i) {//目前是从右往左
		if (i == 0) return number % 3;
		else {
			return (number / (int)pow(3, i)) % 3;
		}
	}
	void plus() { number++; }
private:
	int number;
};

bool Equal(char a[]);

using namespace std;
set<string> sets;
const char map[10][3] = { {},{},{ 'A','B','C' },{ 'D','E','F' },{ 'G','H','I' },{ 'J','K','L' },{ 'M','N','O' },{ 'P','R','S' },{ 'T','U','V' },{ 'W','X','Y' } };
int answernum = 0;
int main_namenum()
{
	//clock_t start;
	//start = clock();
	/*ifstream fin("Section1.2/namenum.in");
	ofstream fout("Section1.2/namenum.out");
	ifstream dic("Section1.2/dict.txt");*/
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream dic("dict.txt");
	
	string temp;
	while(dic>>temp)
	{
		sets.insert(temp);
	}
	char input[13];
	char ch;
	int count = 0;
	while (fin >> ch) {
		input[count++] = ch;
	}
	input[count] = '\0';
	int charnum = strlen(input);
	char *currentString = new char[charnum+1];
	currentString[charnum] = '\0';
	Ternary t;
	int circulation = (int)pow(3, charnum);
	for (int j = 0; j < charnum; j++)
	{
		input[j] = input[j] - '0';
	}
	for (int i = 0; i < circulation; i++)
	{
		for (int j = 0; j < charnum; j++)
		{
			currentString[j] = map[input[j]][t.get(charnum-j-1)];
		}
		t.plus();
		if (Equal(currentString))
		{
			//cout << currentString << endl;
			//cout << "Total Time:" << clock() - start << endl;
			fout << currentString << endl;
			answernum++;
		}
	}
	if(answernum==0)
	fout << "NONE" << endl;
	//cout << "NONE" << endl;
	//cout << "Total Time:" << clock() - start << endl;
	return 0;
}

bool Equal(char a[])
{
	string s = a;
	set<string>::iterator search = sets.find(s);
	if (search != sets.end()) {
		return true;
	}
	else {
		return false;
	}
}