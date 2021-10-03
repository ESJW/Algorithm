#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

long list[MAX];	// �����Ҷ� ����� ���� �迭

void random_create(long data[])
{
	srand((unsigned)time(NULL)); // ���� ����

	for (int i = 0; i < MAX; i++)
	{
		data[i] = (rand() * rand() % MAX);
	}
}
void Merge(long data[], int p, int k, int q) {
	int j = 0;		// ���� �ε���
	int x = p;		// ���� ������ �ε���
	int y = k + 1;	// ������ ������ �ε���
	int z = p;		// ������ ���� �ε��� ǥ��

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

void MergeSort(long data[], int p, int q) {
	int k = 0;	// �߾� ǥ�� ��

	if (p < q) {
		k = (p + q) / 2;
		MergeSort(data, p, k); // 37
		MergeSort(data, k + 1, q); // 11
		Merge(data, p, k, q);
	}
	
}

int main() {
	int *data;
	int count;

	data = (long*)malloc(sizeof(long) * MAX);

	random_create(data);
	MergeSort(data, 0, MAX);
	for (int i = 0; i < 5; i++) {
		printf("���° ���� ����ұ�� >> ");
		scanf("%d", &count);
		printf("%d��° ���� %d�Դϴ�\n", count, data[count]);
	}
}