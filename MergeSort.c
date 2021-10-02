#include <stdio.h>

void MergeSort(int list[], int p, int q) {
	int data[sizeof(list)] = {0};
	int k = 0;

	for (int i = 0; i < sizeof(list); i++)
		data[i] = list[i]; // 37, 10, 22, 30, 35, 13, 25, 24

	if (p < q) {
		k = (p + q) / 2;
		MergeSort(data, p, k); // 37
		MergeSort(data, k + 1, q); // 11
	}
	for (int i = 0; i <= k; i++) {
		if (data[i] < data[k+1]) {
			list[i] = data[i];
			list[i + 1] = data[k+1];
		}
		else {
			list[i] = data[k+1];
			list[i + 1] = data[i];
		}
	}
	int j;
	int x = p;
	int y = k + 1;
	int z = p;

	while (x <= k && y <= q) {
		if (data[z] <= data[y])
			list[z++] = data[x++];
		else
			list[z++] = data[y++];
	}
	if (x > k)
		for (j = y; j <= q; j++)
			list[z++] = data[j];
	else
		for (j = x; j <= q; j++)
			list[z++] = data[j];

	for (j = p; j <= q; j++)
		data[j] = list[j];
}


int main() {
	int A[8] = { 37, 10, 22, 30, 35, 13, 25, 24 };
	MergeSort(A, 0, sizeof(A)-1);
	for (int i = 0; i < sizeof(A); i++)
		printf("%d ", A[i]);
}