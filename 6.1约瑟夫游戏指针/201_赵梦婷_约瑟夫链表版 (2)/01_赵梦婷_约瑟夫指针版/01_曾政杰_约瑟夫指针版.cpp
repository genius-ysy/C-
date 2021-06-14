#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>//头文件

//常量
#define LEN 20
#define OVER "exit"

//结构体
typedef struct ps Person;
struct ps {
	char name[LEN + 1];//姓名
	int pwd;//密码
	Person* next;
};
Person *head = NULL;//指向链表头节点的指针
Person *tail = NULL;//指向链表尾节点的指针
char choice;//存放用户的菜单选项

void InputPerson();//输入操作，初始化链表
void ShowMenu();//显示菜单，并且获得choice
void DisplayLink();//显示链表信息
void ResetPwd();//重置密码
void CountAndQuit();//开始约瑟夫游戏

int num = 0;//记录游戏总人数

int main()
{
	InputPerson();
	while (1)
	{
		ShowMenu();
		switch (choice)
		{
		case '0'://退出程序
			printf("感谢使用，再见\n");
			_getche();
			exit(0);
		case '1'://显示链表
			DisplayLink();
			break;
		case '2'://显示密码
			ResetPwd();
			break;
		case '3'://开始游戏
			CountAndQuit();
			break;
		default:
			printf("选项错误！\n");
		}
	}
}
void InputPerson()//输入操作，初始化链表
{
	Person* p;//新增加的游戏人员
	char name[LEN + 1];//存放人名
	head = tail = NULL;
	while (1)
	{
		printf("请输入第%d个人的信息，输入%s结束：\n", num+1, OVER);
		printf("人名（不超出%d个字符）：\t", LEN);
		scanf_s("%s", name);
		name[LEN] = '\0';
		if (strcmp(name, OVER) == 0)
		{
			return;
		}
		p = (Person*)malloc(sizeof(Person));
		strcpy_s(p->name, name);
		printf("请输入密码（整数）：\t");
		scanf_s("%d", &p->pwd);
		//把新节点加入到链表中
		p->next = head;//新节点连接到head
		if (NULL == head)
			head = tail = p;
		else
		{
			tail->next = p;
			tail = p;
		}
		num++;//人数增加
		printf("\n");
	}
}
void ShowMenu()//显示菜单，并且获得choice
{

}
void DisplayLink()//显示链表信息
{

}
void ResetPwd()//重置密码
{

}
void CountAndQuit()//开始约瑟夫游戏
{

}


