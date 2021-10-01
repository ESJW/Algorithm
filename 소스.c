#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>

#define NUM 100000 // 생성할 난수 갯수

int data_num[NUM]; //총 100000개의 데이터를 생성해서 삽입할 배열을 생성

// 난수 생성 함수
void random_create()
{
	srand((unsigned)time(NULL)); // 난수 생성

	for (int i = 0; i < NUM; i++)
	{
		data_num[i] = (rand()*rand());
	}
}
		///////////////////////////////// 메인 함수 ///////////////////////////////////////////////////////////////
void main() {
	int t; //메뉴 번호를 지정할 변수 생성
	unsigned long start; //sorting하는데 걸린 시간을 알아보기위하여 시작시간을 넣어줄 변수 선언
	unsigned long now; //sorting이 끝나는 시간을 넣어줄 변수 선언

	printf("먼저 100000개의 중복되지 않는 난수를 생성 하겠습니다.\n");
	printf("100000개의 난수를 생성하므로 시간이 좀 걸립니다...기다려주세요...\n");

	random_create(); //난수 생성하는 함수를 호출

}