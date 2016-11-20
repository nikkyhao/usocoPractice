/*
ID: hao.xu.1
PROG: crypt1
LANG: C++
*/

#include <iostream>  
#include <fstream>  
#include <algorithm>  
#include <cstring>  
using namespace std;
bool f[10];     //可用的数字   
int a[10];
bool isok(int temp)
{
	while (temp)
	{
		if (!f[temp % 10]) return false;
		temp /= 10;
	}
	return true;
}
int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int n, temp, k, c1, c2, ans;
	while (fin >> n)
	{
		memset(f, 0, sizeof(f));
		ans = k = 0;
		for (int i = 0; i < n; i++)
		{
			fin >> temp;
			if (!f[temp])
			{
				f[temp] = true;
				a[k++] = temp;
			}
		}
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				for (int m = 0; m < k; m++)
				{
					c1 = a[i] * 100 + a[j] * 10 + a[m];
					for (int x = 0; x < k; x++)
					{
						if (a[x] * c1 >= 1000) continue;
						for (int y = 0; y < k; y++)
						{
							if (a[y] * c1 >= 1000) continue;
							c2 = a[x] * 10 + a[y];
							if (isok(c1*a[x]) && isok(c1*a[y]) && isok(c1*c2))
								ans++;
						}
					}
				}
			}
		}
		fout << ans << endl;
	}
	fout.close();
	return 0;
}