#include<stdio.h>
#include<Windows.h>

void menu_Point();//指针子菜单
void MaxPoint(int *p);//求最大值函数
void MinPoint(int *p);//求最小值函数
void Point()
{
	system("cls");
	int a[10];//声明数组
	int* p = a;
	int key;//监视哨
	printf("请输入10个数\n");
	for (int i = 0; i < 10; i++)//使用循环输入
		scanf_s("%d", &a[i]);
	for (;;)
	{
		system("cls");//清屏
		menu_Point();
		printf("请选择：");
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
		if (key == 0)//返回上级菜单，跳出循环
			break;
	}//for
	system("pause");
}
void menu_Point()
{
	printf("--------Point menu--------\n");
	printf("  1、输出最大值；\n");
	printf("  2、输出最小值；\n");
	printf("  0、返回上一级菜单；\n");
}
void MaxPoint(int *p)//使用指针求最大值
{
	int t = *p;
	for (int i = 0; i < 10; i++)
	{
		if (t < *(p+i))//判断条件
			t = *(p+i);
	}
	printf("最大值是%d\n", t);
	system("pause");
}
void MinPoint(int *p)//使用指针求最小值
{
	int t = *p;
	for (int i = 0; i < 10; i++)
	{
		if (t > *(p + i))//判断条件
			t = *(p + i);
	}
	printf("最小值是%d\n", t);
	system("pause");
}