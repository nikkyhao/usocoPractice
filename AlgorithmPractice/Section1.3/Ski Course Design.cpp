/*
ID: hao.xu.1
PROG: skidesign
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

int hill_height[1000];
int main_skidesign()
{
	//ifstream fin("Section1.3/skidesign.in");
	//ofstream fout("Section1.3/skidesign.out");
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	int N;
	fin >> N;
	std::vector<int> cnt(101, 0);
	for (int i = 0; i < N; ++i)
	{
		int height;
		fin >> height;
		cnt[height]++;
	}

	int low = 0, high = 100;

	while (cnt[low] == 0)
	{
		low++;
	}

	while (cnt[high] == 0)
	{
		high--;
	}

	int mincost = -1;
	for (int l = low; l <= high - 17; ++l)
	{
		int h = l + 17;
		int cost = 0;
		for (int i = low; i < l; ++i)
		{
			if (cnt[i])
			{
				cost += (l - i) * (l - i) * cnt[i];
			}
		}
		for (int i = high; i > h; --i)
		{
			if (cnt[i])
			{
				cost += (i - h) * (i - h) * cnt[i];
			}
		}
		if (mincost < 0 || cost < mincost)
		{
			mincost = cost;
		}
	}
	if (mincost > 0)
		fout << mincost << endl;
	else
		fout << 0 << endl;

	fin.close();
	fout.close();
	return 0;

}



