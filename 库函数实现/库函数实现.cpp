#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>

#define N 20

void personalname();
void StringMenu();//菜单
char* my_strcat(char* dest, const char* src);//两个字符串连接
char* my_copy(char* dest, const char* str);//字符串复制
int my_strlen(const char* str);//字符串长度计算

int main()
{
	int key;//监视哨
	for (;;)
	{
		system("cls");
		StringMenu();
		printf("请选择：");
		scanf_s("%d", &key);
		char c = getchar();//解决scanf输入后回车占用gets函数问题
		switch (key)
		{
		case 1:
		{
			char str1[N + 1], str2[N + 1];
			printf("请输入第一个字符串：(20个字符以内）");
			gets_s(str1);
			str1[N] = '\0';//最后强制加上结束符
			printf("请输入第二个字符串：(20个字符以内）");
			gets_s(str2);
			str2[N] = '\0';//最后强制加上结束符
			char* p1 = str1, * p2 = str2;
			char* ret = my_strcat(p1, p2);
			printf("%s\n", ret);
			system("pause");
			break;
		}
		case 2:
		{
			char str1[N + 1], str2[N + 1];
			printf("请输入第一个字符串：(20个字符以内）");
			gets_s(str1);
			str1[N] = '\0';//最后强制加上结束符
			printf("请输入第二个字符串：(20个字符以内）");
			gets_s(str2);
			str2[N] = '\0';//最后强制加上结束符
			char* p1 = str1, * p2 = str2;
			char* ret = my_copy(p1, p2);
			printf("%s\n", ret);
			system("pause");
			break;
		}
		case 3:
		{
			char str1[N + 1], str2[N + 1];
			printf("请输入字符串：(20个字符以内）");
			gets_s(str1);
			str1[N] = '\0';//最后强制加上结束符
			char* p1 = str1;
			int num = my_strlen(p1);
			printf("%d\n", num);
			system("pause");
			break;
		}
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
	printf("本项目实现了strcat、strcpy、strlen函数\n");
}
void StringMenu()//菜单
{
	//personalname();
	printf("\t\tString Menu\n");
	printf("\t1、strcat\n");
	printf("\t2、strcpy\n");
	printf("\t3、strlen\n");
	printf("\t0、退出\n");
}
char* my_strcat(char* dest, const char* src)//两个字符串连接
{
	char* cp = dest;
	//将dest遍历至\0
	while (*cp) 
	{
		cp++;
	}
	//将src内容复制在dest之后
	while (*cp++ = *src++) 
	{
		;
	}
	return dest;
}
char* my_copy(char* dest, const char* str)//字符串复制
{
	char* ret = dest;  //将目的指针保留，因为执行完下面的语句，目的指针dest已经指向字符串末尾
	while (*dest++ = *str++)  //只要原字符串中字符不为\0,完成复制
		;
	return ret;

}
int my_strlen(const char* str)//字符串长度计算
{
	int count = 0;
	const char* star = str;  //定义指针star,并且指向和指针str指向相同的空间
	while (*str)  //只要str指向的内容不为\0,就将指针向后移动，并且计数器加加
	{
		count++;
		str++;
	}
	return str - star;  //跳出while循环时，str指向最后一个字符串的下一个位置（‘\0’处）
}