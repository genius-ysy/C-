#include<stdio.h>
#include<Windows.h>

void menu_Point();//ָ���Ӳ˵�
void MaxPoint(int *p);//�����ֵ����
void MinPoint(int *p);//����Сֵ����
void Point()
{
	system("cls");
	int a[10];//��������
	int* p = a;
	int key;//������
	printf("������10����\n");
	for (int i = 0; i < 10; i++)//ʹ��ѭ������
		scanf_s("%d", &a[i]);
	for (;;)
	{
		system("cls");//����
		menu_Point();
		printf("��ѡ��");
		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			MaxPoint(p);
			break;
		case 2:
			MinPoint(p);
			break;
		default:
			break;
		}//switch
		if (key == 0)//�����ϼ��˵�������ѭ��
			break;
	}//for
	system("pause");
}
void menu_Point()
{
	printf("--------Point menu--------\n");
	printf("  1��������ֵ��\n");
	printf("  2�������Сֵ��\n");
	printf("  0��������һ���˵���\n");
}
void MaxPoint(int *p)//ʹ��ָ�������ֵ
{
	int t = *p;
	for (int i = 0; i < 10; i++)
	{
		if (t < *(p+i))//�ж�����
			t = *(p+i);
	}
	printf("���ֵ��%d\n", t);
	system("pause");
}
void MinPoint(int *p)//ʹ��ָ������Сֵ
{
	int t = *p;
	for (int i = 0; i < 10; i++)
	{
		if (t > *(p + i))//�ж�����
			t = *(p + i);
	}
	printf("��Сֵ��%d\n", t);
	system("pause");
}