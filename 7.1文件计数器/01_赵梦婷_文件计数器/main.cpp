#include "stdio.h"//文件处理需要
#include "stdlib.h"//system()需要 
#define FilePath "counter.dat"//数据文件的位置，可以根据实际情况修改
int readCounter(char *path);//从文件中读取程序运行的次数
void writeCounter(int count,char* path);//将当前程序运行的次数写入文件
int main()
{
	int count=0;//临时变量，用于计算当前程序运行的次数
//从文件中读取数据，并计算当前程序运行的次数
	printf("班级：19软工2班\n姓名：曾政杰\n学号：201910414201\n");
	printf("拓展：利用fgetc和fputc进行读取和写入\n");
	count=readCounter(FilePath)+1;
	printf("该程序已运行：%d次\n",count);
	printf("----------------------------\n");
	printf("下面将运行次数写入计数器文件（counter.dat）......\n");
	writeCounter(count,FilePath);
	printf("写入文件结束！\n");
	printf("程序运行结束！\n");
	printf("----------------------------\n");
	system("pause");
}
int readCounter (char *path)//从文件中读取程序运行的次数
{
	FILE* fp;
	int count;
	
	if((fp=fopen(path,"r"))==NULL)
	{
		printf("没有计数器文件：counter.dat,保存运行次数时将新建文件夹！\n");
		return 0;
	}
	//fscanf(fp,"%d",&count);
	count=fgetc(fp);    //读取第一个字符
	
	fclose(fp);
	return count;
}
void writeCounter(int count,char *path)//将当前程序运行的次数写入文件
{
	FILE *fp;
	if((fp=fopen(path,"w"))==NULL)
	{
		printf("无法创建计数器文件文件夹！\n");
		return;
	}
	//fprintf(fp,"%d",count);
	fputc(count,fp);
	fclose(fp);
}

