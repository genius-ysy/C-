#include<stdio.h>
#include<Windows.h>
#include"ModleArray.h"
#include"ModlePoint.h"

void name();
void menu();
int main()
{
	
	int key;//������
	for (;;)
	{
		system("cls");
		name();
		menu();
		printf("��ѡ��");
		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			Array();
			break;
		case 2:
			Point();
			break;
		default:
			break;
		}//switch
		if (key == 0)
			break;
	}//for
	system("pause");
}
void name()
{
	printf("�༶����2��\n������������\nѧ�ţ�201910414201\n");
	printf("����Ŀͨ��ͷ�ļ�����ʵ�������顢ָ����������Сֵ\n");
}
void menu()
{
	printf("--------main menu--------\n");
	printf("  1��ʹ�����飻\n");
	printf("  2��ʹ��ָ�룻\n");
	printf("  0�������˵���\n");
}