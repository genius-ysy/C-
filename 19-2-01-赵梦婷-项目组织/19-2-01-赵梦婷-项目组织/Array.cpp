#include<stdio.h>
#include<Windows.h>

void menu_Array();//数组子菜单
void MaxArray(int a[]);//求最大值函数
void MinArray(int a[]);//求最小值函数
void Array()
{
	system("cls");
	int a[10];//声明数组
	int key;//监视哨
	printf("请输入10个数\n");
	for (int i = 0; i < 10; i++)//使用循环输入
		scanf_s("%d", &a[i]);
	for (;;)
	{
		system("cls");
		menu_Array();
		printf("请选择：");
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
		if (key == 0)//返回上级菜单，跳出循环
			break;
	}//for
	system("pause");
}
void menu_Array()
{
	printf("--------Array menu--------\n");
	printf("  1、输出最大值；\n");
	printf("  2、输出最小值；\n");
	printf("  0、返回上一级菜单；\n");
}
void MaxArray(int a[])
{
	int t=a[0];//中间量
	for (int i = 0; i < 10; i++)
	{
		if (t < a[i])//判断条件
			t = a[i];
	}
	printf("最大值是%d\n", t);
	system("pause");
}
void MinArray(int a[])
{
	int t = a[0];//中间量
	for (int i = 0; i < 10; i++)
	{
		if (t > a[i])//判断条件
			t = a[i];
	}
	printf("最小值是%d\n", t);
	system("pause");
}