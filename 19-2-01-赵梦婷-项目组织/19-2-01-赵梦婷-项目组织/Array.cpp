#include<stdio.h>
#include<Windows.h>

void menu_Array();//�����Ӳ˵�
void MaxArray(int a[]);//�����ֵ����
void MinArray(int a[]);//����Сֵ����
void Array()
{
	system("cls");
	int a[10];//��������
	int key;//������
	printf("������10����\n");
	for (int i = 0; i < 10; i++)//ʹ��ѭ������
		scanf_s("%d", &a[i]);
	for (;;)
	{
		system("cls");
		menu_Array();
		printf("��ѡ��");
		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			MaxArray(a);
			break;
		case 2:
			MinArray(a);
			break;
		default:
			break;
		}//switch
		if (key == 0)//�����ϼ��˵�������ѭ��
			break;
	}//for
	system("pause");
}
void menu_Array()
{
	printf("--------Array menu--------\n");
	printf("  1��������ֵ��\n");
	printf("  2�������Сֵ��\n");
	printf("  0��������һ���˵���\n");
}
void MaxArray(int a[])
{
	int t=a[0];//�м���
	for (int i = 0; i < 10; i++)
	{
		if (t < a[i])//�ж�����
			t = a[i];
	}
	printf("���ֵ��%d\n", t);
	system("pause");
}
void MinArray(int a[])
{
	int t = a[0];//�м���
	for (int i = 0; i < 10; i++)
	{
		if (t > a[i])//�ж�����
			t = a[i];
	}
	printf("��Сֵ��%d\n", t);
	system("pause");
}