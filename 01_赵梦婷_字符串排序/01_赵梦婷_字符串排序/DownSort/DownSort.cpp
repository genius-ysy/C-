#include<stdio.h>
#include<string.h>
#include<Windows.h>

#define N 5 //����������
#define M 26 //���ʳ�������

void SortDownMenu();//����˵�
void DownBubble(char word[N][M + 1]);//����ð���㷨
void DownSelection(char word[N][M + 1]);//����ѡ���㷨
void DownInsertion(char word[N][M + 1]);//��������㷨

void DownSort(char word[N][M+1])//��������
{
	int key;//������
	for (;;)
	{
		system("cls");
		SortDownMenu();
		printf("��ѡ��");
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
void SortDownMenu()//����˵�
{
	printf("--------Down Sort Menu--------\n");
	printf("  1��ð������\n");
	printf("  2��ѡ������\n");
	printf("  3����������\n");
	printf("  0�������˵���\n");
}
void DownBubble(char word[N][M + 1])//����ð���㷨
{
	int i = 0, j = 0;//ѭ������
	char temp[M + 1];//��ʱ����
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
		printf("��������Ϊ%s\n", word[i]);
	system("pause");
}
void DownSelection(char word[N][M + 1])//����ѡ���㷨
{
	int i = 0, j = 0;//ѭ������
	char temp[M + 1];//��ʱ����
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			if (word[i] < word[j])//���бȽ�
	   //�ȽϺ���н���
			{
				strcpy_s(temp, word[i]);
				strcpy_s(word[i], word[j]);
				strcpy_s(word[j], temp);
			}
	}
	for (int i = 0; i < N; i++)
		printf("��������Ϊ%s\n", word[i]);
	system("pause");

}
void DownInsertion(char word[N][M + 1])//��������㷨
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
		printf("��������Ϊ%s\n", word[i]);
	system("pause");
}