#define _CRT_SECURE_NO_WARNINGS

// HanoiTower Solution

// 막대 A,B,C가 있을 때 A에 있는 n개의 원반을 C로 옮겨야 한다.

// 1. n-1 개를 A에서 B로 이동
// 2. A에 남은 맨 아래의 가장 큰 원반 1개를 C로 이동
// 3. B의 n-1 개의 원반을 C로 이동

#include<stdio.h>

//from에 꽂혀있는 num개의 원반을 by를 거쳐서 to로 이동
void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)	//이동할 원반의 수가 1개라면
	{
		printf("원반1을 %c에서 %c로 이동 \n", from, by);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);	//3단계 중 1단계
		printf("원반%d을 %c에서 %c로 이동 \n",num, from, by);	//3단계 중 2단계
		HanoiTowerMove(num - 1, by, to, from);	//3단계중 3단계
	}
}

int main(void)
{
	//막대 A의 원반 3개를 막대 B를 경유하여 막대 C로 옮기기
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}
