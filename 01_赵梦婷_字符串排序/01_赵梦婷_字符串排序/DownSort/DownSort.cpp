#include<stdio.h>
#include<string.h>
#include<Windows.h>

#define N 5 //单词数上限
#define M 26 //单词长度上限

void SortDownMenu();//降序菜单
void DownBubble(char word[N][M + 1]);//降序冒泡算法
void DownSelection(char word[N][M + 1]);//降序选择算法
void DownInsertion(char word[N][M + 1]);//降序插入算法

void DownSort(char word[N][M+1])//降序排列
{
	int key;//监视哨
	for (;;)
	{
		system("cls");
		SortDownMenu();
		printf("请选择：");
		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			DownBubble(word);
			break;
		case 2:
			DownSelection(word);
			break;
		case 3:
			DownInsertion(word);
			break;
		default:
			break;
		}//switch
		if (key == 0)
			break;
	}//for
	system("pause");
}
void SortDownMenu()//升序菜单
{
	printf("--------Down Sort Menu--------\n");
	printf("  1、冒泡排序；\n");
	printf("  2、选择排序；\n");
	printf("  3、插入排序；\n");
	printf("  0、结束菜单；\n");
}
void DownBubble(char word[N][M + 1])//降序冒泡算法
{
	int i = 0, j = 0;//循环变量
	char temp[M + 1];//临时变量
	for (j = 0; j < N - 1; j++)
	{
		for (i = 0; i < N - 1 - j; i++)
		{
			if (strcmp(word[i], word[i + 1]) > 0)
			{
				strcpy_s(temp, word[i]);
				strcpy_s(word[i], word[i + 1]);
				strcpy_s(word[i + 1], temp);


			}
		}
	}
	for (int i = N-1; i >= 0; i--)
		printf("降序排列为%s\n", word[i]);
	system("pause");
}
void DownSelection(char word[N][M + 1])//降序选择算法
{
	int i = 0, j = 0;//循环变量
	char temp[M + 1];//临时变量
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			if (word[i] < word[j])//进行比较
	   //比较后进行交换
			{
				strcpy_s(temp, word[i]);
				strcpy_s(word[i], word[j]);
				strcpy_s(word[j], temp);
			}
	}
	for (int i = 0; i < N; i++)
		printf("升序排列为%s\n", word[i]);
	system("pause");

}
void DownInsertion(char word[N][M + 1])//降序插入算法
{
	char temp[M];
	int i, j;
	for (i = 1; i < N; i++)
	{
		strcpy_s(temp, word[i]);
		j = i;
		while (j >= 1 && 1 == strcmp(word[j - 1], temp))
		{
			strcpy_s(word[j], word[j - 1]);
			j--;
		}
		strcpy_s(word[j], temp);
	}
	for (int i = N-1; i >= 0; i--)
		printf("降序排列为%s\n", word[i]);
	system("pause");
}