#include "stdio.h"//�ļ�������Ҫ
#include "stdlib.h"//system()��Ҫ 
#define FilePath "counter.dat"//�����ļ���λ�ã����Ը���ʵ������޸�
int readCounter(char *path);//���ļ��ж�ȡ�������еĴ���
void writeCounter(int count,char* path);//����ǰ�������еĴ���д���ļ�
int main()
{
	int count=0;//��ʱ���������ڼ��㵱ǰ�������еĴ���
//���ļ��ж�ȡ���ݣ������㵱ǰ�������еĴ���
	printf("�༶��19��2��\n������������\nѧ�ţ�201910414201\n");
	printf("��չ������fgetc��fputc���ж�ȡ��д��\n");
	count=readCounter(FilePath)+1;
	printf("�ó��������У�%d��\n",count);
	printf("----------------------------\n");
	printf("���潫���д���д��������ļ���counter.dat��......\n");
	writeCounter(count,FilePath);
	printf("д���ļ�������\n");
	printf("�������н�����\n");
	printf("----------------------------\n");
	system("pause");
}
int readCounter (char *path)//���ļ��ж�ȡ�������еĴ���
{
	FILE* fp;
	int count;
	
	if((fp=fopen(path,"r"))==NULL)
	{
		printf("û�м������ļ���counter.dat,�������д���ʱ���½��ļ��У�\n");
		return 0;
	}
	//fscanf(fp,"%d",&count);
	count=fgetc(fp);    //��ȡ��һ���ַ�
	
	fclose(fp);
	return count;
}
void writeCounter(int count,char *path)//����ǰ�������еĴ���д���ļ�
{
	FILE *fp;
	if((fp=fopen(path,"w"))==NULL)
	{
		printf("�޷������������ļ��ļ��У�\n");
		return;
	}
	//fprintf(fp,"%d",count);
	fputc(count,fp);
	fclose(fp);
}

