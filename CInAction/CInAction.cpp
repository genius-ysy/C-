#include<stdio.h>
#include<Windows.h>//系统头文件
#include"HeadFile/Practice1/Practice1.h"
#include"HeadFile/Practice2/Practice2.h"
#include"HeadFile/Practice3/Practice3.h"
#include"HeadFile/Practice4/Practice4.h"
#include"HeadFile/Practice5/Practice5.h"
#include"HeadFile/Practice6/Practice6.h"
#include"HeadFile/Practice7/Practice7.h"
#include"HeadFile/Practice8/Practice8.h"
#include"HeadFile/Practice9/Practice9.h"



void name();//个人信息
void menu();//主菜单
int main()
{
	int key;//监视哨
	for (;;)
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			Practice_1();
			break;
		case 2:
			Practice_2();
			break;
		case 3:
			Practice3();
			break;
		case 4:
			Practice4();
			break;
		case 5:
			Practice5();
			break;
		case 6:
			Practice6();
			break;
		case 7:
			Practice7();
			break;
		case 8:
			Practice8();
			break;
		case 9:
			Practice9();
			break;
		default:
			break;
		}//switch
		if (key == 10)
			break;
	}//for
	system("pause");
}
void name()
{
	printf("班级：软工2班\n姓名：曾政杰\n学号：201910414201\n");
	printf("通过项目组织将实战1，实战2组合起来\n");
}
void menu()
{
	system("cls");
	name();
	printf("--------Main Menu--------\n");
	printf("  1、实战1；\n");
	printf("  2、实战2；\n");
	printf("  3、实战3；\n");
	printf("  4、实战4；\n");
	printf("  5、实战5；\n");
	printf("  6、实战6；\n");
	printf("  7、实战7；\n");
	printf("  8、实战8；\n");
	printf("  9、实战9；\n");
	printf("  10、结束菜单；\n");
}
