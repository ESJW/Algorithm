#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int list[MAX];	// �����Ҷ� ����� ���� �迭

void random_create(int data[])
{
	srand((unsigned)time(NULL)); // ���� ����

	for (int i = 0; i < MAX; i++)
	{
		data[i] = (rand() * rand());
	}
}
void Merge(int data[], int p, int k, int q) {
	int j = 0;		// ���� �ε���
	int x = p;		// ���� ������ �ε���
	int y = k + 1;	// ������ ������ �ε���
	int z = p;		// list�� �պ��� �� ���

	while (x <= k && y <= q) {
		if (data[x] <= data[y])
			list[z++] = data[x++];
		else
			list[z++] = data[y++];
	}
	if (x > k)
		for (j = y; j <= q; j++)
			list[z++] = data[j];
	else
		for (j = x; j <= k; j++)
			list[z++] = data[j];

	for (j = p; j <= q; j++) // ���ĵ� ������ ����
		data[j] = list[j];
}

void MergeSort(int data[], int p, int q) {
	int k = 0;	// �߾� ǥ�� ��

	if (p < q) {
		k = (p + q) / 2;
		MergeSort(data, p, k); // 37
		MergeSort(data, k + 1, q); // 11
		Merge(data, p, k, q);
	}
	
}
int main() {
	int data[MAX];
	random_create(data);
	MergeSort(data, 0, MAX);

}