/*
ID: hao.xu.1
PROG: wormhole
LANG: C++
*/

#include<fstream>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n, x[13], y[13];
int next_to_right[13];
int partner[13];

bool cycle_exist()
{
	for (int start = 1; start <= n; start++) {
		int pos = start;
		for (int count = 0; count  < n; count++)
			pos = next_to_right[partner[pos]];
		if (pos != 0)
			return true;
	}
		return false;
}

//通过遍历解决问题
// count all solutions  
int solve(void)
{
	// find first unpaired wormhole  
	int i, total = 0;
	for (i = 1; i <= n; i++)
		if (partner[i] == 0) break;

	// everyone paired?  
	if (i > n) {
		if (cycle_exist()) return 1;
		else return 0;
	}

	// try pairing i with all possible other wormholes j  
	for (int j = i + 1; j <= n; j++)
		if (partner[j] == 0) {
			// try pairing i & j, let recursion continue to  
			// generate the rest of the solution  
			partner[i] = j;
			partner[j] = i;
			total += solve();
			partner[i] = partner[j] = 0;
		}
	return total;
}
int main()
{
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	fin >> n;
	for (int i = 1; i <=n; i++) fin >> x[i] >> y[i];
	fin.close();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (y[i] == y[j] && x[i] < x[j])
				if (next_to_right[i]==0||x[j]<x[next_to_right[i]])
					next_to_right[i] = j;


	fout << solve() << endl;
	return 0;
}





