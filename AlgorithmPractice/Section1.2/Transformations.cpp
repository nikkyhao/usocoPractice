/*
ID: hao.xu.1
PROG: transform
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


class Mat {
public:
	Mat(int dimention) { 
		this->dimention = dimention; 
	}
	//~Mat() { delete mat; } 加上这一行会出现问题，以后解决
	char get(int i, int j) { return mat[i][j]; }
	bool equal(Mat mat);
	void rotate_90();//rotate 90 degree clockwise.
	void rotate_180();
	void rotate_270();
	void reflect();//reflect horisontal
	void show();
	char mat[10][10];
private:
	int dimention;
};

	int dimention;
	Mat* beforeMat;
	Mat* afterMat;
	

	int main_transform()
{
	//ifstream fin("Section1.2/transform.in");
	//ofstream fout("Section1.2/transform.out");
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	fin >> dimention;
	beforeMat = new Mat(dimention); afterMat = new Mat(dimention);
	for (int i = 0; i < dimention; i++)
	{
		for (int j = 0; j < dimention; j++)
		{
			fin >> beforeMat->mat[i][j];
		}
	}
	for (int i = 0; i < dimention; i++)
	{
		for (int j = 0; j < dimention; j++)
		{
			fin >> afterMat->mat[i][j];
		}
	}
	
	//rotation123
	for (int i = 0; i < 4; i++)
	{
		beforeMat->rotate_90();
		if (beforeMat->equal(*afterMat))
		{
			fout << i + 1 << endl; return 0;
		}
	}
	//reflection4
	beforeMat->reflect();
	if (beforeMat->equal(*afterMat)) {
		fout << 4 << endl; return 0;
	}
	//combination5
	for (int i = 0; i < 4; i++)
	{
		beforeMat->rotate_90();
		if (beforeMat->equal(*afterMat))
		{
			fout << 5 << endl; return 0;
		}
	}
	beforeMat->reflect();
	// nochange6
	if (beforeMat->equal(*afterMat)) {
		fout << 6 << endl; return 0;
	}
		
	fout << 7 << endl;

	return 0;
}



bool Mat::equal(Mat matt)//C++中0表示假，非0表示真
{
	bool equall = true;
	for (int i = 0; i < dimention; i++)
	{
		for (int j = 0; j < dimention; j++)
		{
			if (mat[i][j] !=matt.get(i, j)) equall = false;
		}
	}
	return equall;
}

void Mat::rotate_90()
{
	char a[10][10];
	for (int i = 0; i < dimention; i++)
	{
		for (int j = 0; j < dimention; j++)
		{
			a[j][dimention - 1 - i] = mat[i][j];
		}
	}
	memcpy(mat, a, sizeof(a));//把a的值整体赋值给mat
}

void Mat::reflect()
{
	char a[10][10];
	for (int i = 0; i < dimention; i++)
	{
		for (int j = 0; j < dimention; j++)
		{
			a[i][dimention-1-j] = mat[i][j];
		}
	}
	memcpy(mat, a, sizeof(a));//把a的值整体赋值给mat
}

void Mat::rotate_180()
{
	char a[10][10];
	for (int i = 0; i < dimention; i++)
	{
		for (int j = 0; j < dimention; j++)
		{
			a[dimention-1-i][dimention-1-j] = mat[i][j];
		}
	}
	memcpy(mat, a, sizeof(a));//把a的值整体赋值给mat
}

void Mat::rotate_270()
{
	char a[10][10];
	for (int i = 0; i < dimention; i++)
	{
		for (int j = 0; j < dimention; j++)
		{
			a[dimention-1-j][i] = mat[i][j];
		}
	}
	memcpy(mat, a, sizeof(a));//把a的值整体赋值给mat
}

void Mat::show()
{
	for (int i = 0; i < dimention; i++)
	{
		for (int j = 0; j < dimention; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}