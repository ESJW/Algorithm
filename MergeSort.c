#include <stdio.h>

void MergeSort(int data[], int p, int q) {
	if (p < q) {
		int k = (p + q) / 2;
		MergeSort(data, p, k);
		MergeSort(data, k + 1, q);
	}
}

int main() {
	int A[] = (19, 23, 4, 5, 64, 2);
	MergeSort(A,0,)
}