#include<stdio.h>
#include<Windows.h>
#include"ModleArray.h"
#include"ModlePoint.h"

void name();
void menu();
int main()
{
	
	int key;//监视哨
	for (;;)
	{
		system("cls");
		name();
		menu();
		printf("请选择：");
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
	printf("班级：软工2班\n姓名：曾政杰\n学号：201910414201\n");
	printf("本项目通过头文件引用实现用数组、指针输出最大最小值\n");
}
void menu()
{
	printf("--------main menu--------\n");
	printf("  1、使用数组；\n");
	printf("  2、使用指针；\n");
	printf("  0、结束菜单；\n");
}