/*
ID: hao.xu.1
PROG: milk2
LANG: C++
*/
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int a;s
	int b;
};
void SortBya(Node node[], int length);
void quick(Node[], int, int);
int min(int a, int b);
int max(int a, int b);

Node nodes[5000];
vector<Node> vec;


int main_milk2()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int num;
	fin >> num;
	for (int i = 0; i < num; i++)
	{
		int a; fin >> a;
		int b; fin >> b;
		nodes[i].a = a;
		nodes[i].b = b;
	}
	SortBya(nodes, num);
	int start = nodes[0].a, end = nodes[0].b;
	int current = 1;
	while (current < num)
	{
		Node temp = nodes[current];
		if (temp.a <= end) {
			end = max(end, temp.b);
			start = min(start, temp.a);
		}
		if (temp.a > end) {
			Node node; node.a = start; node.b = end;
			vec.push_back(node);
			start = nodes[current ].a;
			end = nodes[current ].b;
		}
		current++;
	}
	//存入最后一个 
	Node node; node.a = start; node.b = end;
	vec.push_back(node);


	int max_duration, max_interval;
	max_duration = vec[0].b - vec[0].a;
	for (int i = 1; i < vec.size(); i++)
	{
		int result = vec[i].b - vec[i].a;
		if (result > max_duration)  max_duration = result;
	}

	if (vec.size() >= 2) {
		max_interval = vec[1].a - vec[0].b;
		for (int i = 1; i < vec.size()-1; i++)
		{
			int result_interval = vec[i + 1].a - vec[i].b;
			if (result_interval > max_interval) max_interval = result_interval;
		}
	}
	else {
		max_interval = 0;
	}
	fout << max_duration << " " << max_interval << endl;
	return 0;
}

void SortBya(Node node[],int length)//按照每个node的开始位置进行排序
{
	quick(node, 0, length-1);
}
void quick(Node node[], int start, int end)//包含start与end
{
	if (start < end)
	{
		int i = start;
		int j = end;
		Node temp = node[start];
		int mid = start;
		while (i < j)
		{
			while (i<j && node[j].a > temp.a)
				j--;
			if (i < j) {
				node[i++] = node[j];
				mid = j;
			}
			while (i < j && node[i].a < temp.a) i++;
			if (i < j) {
				node[j--] = node[i];
				mid = i;
			}
		}
		node[mid] = temp;
		quick(node, start, i - 1);
		quick(node, i + 1, end);
	}
}
int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}