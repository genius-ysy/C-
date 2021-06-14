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

void Line();//划线 
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
			printf("\n感谢使用，再见\n");
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
			printf("\n选项错误！\n");
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
		scanf("%s", name);
		name[LEN] = '\0';
		if (strcmp(name, OVER) == 0)
		{
			return;
		}
		p = (Person*)malloc(sizeof(Person));
		strcpy(p->name, name);
		printf("请输入密码（整数）：\t");
		scanf("%d", &p->pwd);
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
void Line()
{
	printf("\n——————————————————\n");
}
void ShowMenu()//显示菜单，并且获得choice
{
	while(1)
	{
		Line();
		printf("\t请选择操作:\n");
		printf("\t1、显示信息\n");
		printf("\t2、重新输入每个人密码\n");
		printf("\t3、开始游戏\n");
		printf("\t0、退出游戏\n");
		printf("\t请输入正确选项：");
		choice=getche();
		if((choice-'0')>=0&&(choice-'0')<4)
			return;
	}
}
void DisplayLink()//显示链表信息
{
		
	int i=0;
	Person *p=head;//从头节点开始
	if(NULL==p)//如果没有就终止 
		return; 
	Line();
	printf("\n\t当前链表信息如下：\n");
	printf("\t%2d:\t%s\t%d\n",++i,p->name,p->pwd);
	p=p->next;
	while(p!=head)
	{
		printf("\t%2d:\t%s\t%d\n",++i,p->name,p->pwd);
		p=p->next;
	}
	Line();
}
void ResetPwd()//重置密码
{
	int i=0;
	Person *p=head;//从头节点开始
	if(NULL==p)//如果没有就终止 
		return; 
	Line();
	//先处理第一个人密码
	printf("%s",p->name);
	scanf("%d",&p->pwd);
	p=p->next;
	while(p!=head)
	{
		printf("%s",p->name);
		scanf("%d",&p->pwd);
		p=p->next;
	}
	Line();
}
void CountAndQuit()//开始约瑟夫游戏
{
	int i,n,pwd;//用于循环变量，计数，保存当前密码 
	//先复制链表
	Person *p,*c,*q;//分别指向临时结点，新链表的当前结点，当前结点的前结点
	Person *head2,*tail2;//分别指向新链表的头、尾结点
	head2=tail2=NULL;
	c=head;
	//首节点不能为NULL
	if(NULL==head)
		return;
	//先复制头结点
	p=(Person*)malloc(sizeof(Person));
	strcpy(p->name,c->name);
	p->pwd=c->pwd;
	p->next=p;
	head2=tail2=p;//链表成环
	//复制其他节点
	c=c->next; 
	while(c!=head)
	{
		p=(Person*)malloc(sizeof(Person));
		strcpy(p->name,c->name);
		p->pwd=c->pwd;
		//将新节点插入到新链表中 
		p->next=head2;
		tail2->next=p;
		tail2=p;
		c=c->next;
	}
	//开始游戏
	Line();
	printf("\n\t游戏处理如下：\n"); 
	i=0;
	c=head2;//当前指针指向新链表头结点 
	q=tail2;//当前节点前节点，指向新链表的尾结点
	pwd=c->pwd;
	while(c->next!=c)
	{
		n=1;
		while(n<pwd)
		{
			q=c;
			c=c->next;
			n++;
		}
		//当前指针c所指的人退出
		q->next=c->next;
		printf("\t第%d个退出者：%s\n",++i,c->name);
		pwd=c->pwd;//退出者密码作为下一个数数的依据 
		free(c);
		c=q->next; 
	} 
	//最后一个退出的人
	 printf("\t第%d个退出者：%s",++i,c->name);
	 free(c);
	Line();
	
}

