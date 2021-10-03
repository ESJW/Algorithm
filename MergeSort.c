#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

long list[MAX];	// 정렬할때 사용할 보조 배열

void random_create(long data[])
{
	srand((unsigned)time(NULL)); // 난수 생성

	for (int i = 0; i < MAX; i++)
	{
		data[i] = (rand() * rand() % MAX);
	}
}
void Merge(long data[], int p, int k, int q) {
	int j = 0;		// 보조 인덱스
	int x = p;		// 왼쪽 데이터 인덱스
	int y = k + 1;	// 오른쪽 데이터 인덱스
	int z = p;		// 데이터 넣을 인덱스 표시

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

	for (j = p; j <= q; j++) // 정렬된 데이터 복사
		data[j] = list[j];
}

void MergeSort(long data[], int p, int q) {
	int k = 0;	// 중앙 표시 값

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
		printf("몇번째 수를 출력할까요 >> ");
		scanf("%d", &count);
		printf("%d번째 수는 %d입니다\n", count, data[count]);
	}
}