#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>

#define NUM 100000 // ������ ���� ����

int data_num[NUM]; //�� 100000���� �����͸� �����ؼ� ������ �迭�� ����

// ���� ���� �Լ�
void random_create()
{
	srand((unsigned)time(NULL)); // ���� ����

	for (int i = 0; i < NUM; i++)
	{
		data_num[i] = (rand()*rand());
	}
}
		///////////////////////////////// ���� �Լ� ///////////////////////////////////////////////////////////////
void main() {
	int t; //�޴� ��ȣ�� ������ ���� ����
	unsigned long start; //sorting�ϴµ� �ɸ� �ð��� �˾ƺ������Ͽ� ���۽ð��� �־��� ���� ����
	unsigned long now; //sorting�� ������ �ð��� �־��� ���� ����

	printf("���� 100000���� �ߺ����� �ʴ� ������ ���� �ϰڽ��ϴ�.\n");
	printf("100000���� ������ �����ϹǷ� �ð��� �� �ɸ��ϴ�...��ٷ��ּ���...\n");

	random_create(); //���� �����ϴ� �Լ��� ȣ��

}