#define _CRT_SECURE_NO_WARNINGS

// HanoiTower Solution

// ���� A,B,C�� ���� �� A�� �ִ� n���� ������ C�� �Űܾ� �Ѵ�.

// 1. n-1 ���� A���� B�� �̵�
// 2. A�� ���� �� �Ʒ��� ���� ū ���� 1���� C�� �̵�
// 3. B�� n-1 ���� ������ C�� �̵�

#include<stdio.h>

//from�� �����ִ� num���� ������ by�� ���ļ� to�� �̵�
void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)	//�̵��� ������ ���� 1�����
	{
		printf("����1�� %c���� %c�� �̵� \n", from, by);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);	//3�ܰ� �� 1�ܰ�
		printf("����%d�� %c���� %c�� �̵� \n",num, from, by);	//3�ܰ� �� 2�ܰ�
		HanoiTowerMove(num - 1, by, to, from);	//3�ܰ��� 3�ܰ�
	}
}

int main(void)
{
	//���� A�� ���� 3���� ���� B�� �����Ͽ� ���� C�� �ű��
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}
