/*
ID: hao.xu.1
PROG: barn1
LANG: C++
*/

#include<fstream>
#include<iostream>
#include<vector>

int find_max(int arr[], int c) {
	int max = -1;
	int max_index = -1;
	int i;

	for (i = 0; i<c; i++) {
		if (arr[i] >= max) {
			max = arr[i];
			max_index = i;
		}
	}

	return max_index;
}

void sort_arr(int arr[], int c) {
	int i, j, temp;

	for (i = c - 1; i>0; i--) {
		for (j = 0; j<i; j++) {
			if (arr[j]>arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main(void) {
	int m, s, c, i, total, index;
	FILE *fin = fopen("barn1.in", "r");
	FILE *fout = fopen("barn1.out", "w");

	fscanf(fin, "%d %d %d", &m, &s, &c);

	int * arr = (int *)malloc(c * sizeof(int));
	int * arr_gap = (int *)malloc(c * sizeof(int));

	for (i = 0; i<c; i++) {
		fscanf(fin, "%d", &arr[i]);
	}

	sort_arr(arr, c);

	arr_gap[0] = 0;
	for (i = 1; i<c; i++) {
		arr_gap[i] = arr[i] - arr[i - 1];
	}

	if (m >= c) {
		total = c;
	}
	else {
		total = arr[c - 1] - arr[0] + 1;

		for (i = 1; i<m; i++) {
			index = find_max(arr_gap, c);
			total -= (arr_gap[index] - 1);
			arr_gap[index] = 0;
		}
	}
	fprintf(fout, "%d\n", total);
	return 0;
}