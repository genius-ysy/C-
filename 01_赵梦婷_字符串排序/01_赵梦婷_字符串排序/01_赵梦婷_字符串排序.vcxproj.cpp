#include<stdio.h>
#include<string.h>
#include<Windows.h>

#include"HeadFile/DownSort.h"
#include"HeadFile/UpSort.h"

#define N 5 //单词数上限
#define M 26 //单词长度上限

void personalname();//个人信息
void SortMenu();//主菜单


int main()
{
	int key;//监视哨
	for (;;)
	{
		system("cls");
		personalname();
		char word[N][M+1];//数组声明
		printf("请输入%d个单词（每个单词不超过26个字母）\n",N);
		for (int i = 0; i < N; i++)//单词的输入
		{
			scanf_s("%s", &word[i], sizeof(word));
			word[i][M] = '\0';
		}
		SortMenu();//菜单
		printf("请选择：");
		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			UpSort(word);
			break;
		case 2:
			DownSort(word);
			break;
		default:
			break;
		}//switch
		if (key == 0)
			break;
	}//for
	system("pause");
}
void personalname()
{
	printf("班级：19软工2班\n姓名：曾政杰\n学号：201910414201\n");
	printf("本项目采用实战3菜单类设计，将升序降序分别列为单独的c文件\n");
	printf("拓展：可以进行升序、降序排列，都可以采用冒泡、选择、插入算法进行排序\n");
}
void SortMenu()//主菜单
{
	printf("--------Sort Menu--------\n");
	printf("  1、升序排列；\n");
	printf("  2、降序排列；\n");
	printf("  0、结束菜单；\n");
}
