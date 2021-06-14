#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>//ͷ�ļ�

//����
#define LEN 20
#define OVER "exit"

//�ṹ��
typedef struct ps Person;
struct ps {
	char name[LEN + 1];//����
	int pwd;//����
	Person* next;
};
Person *head = NULL;//ָ������ͷ�ڵ��ָ��
Person *tail = NULL;//ָ������β�ڵ��ָ��
char choice;//����û��Ĳ˵�ѡ��

void Line();//���� 
void InputPerson();//�����������ʼ������
void ShowMenu();//��ʾ�˵������һ��choice
void DisplayLink();//��ʾ������Ϣ
void ResetPwd();//��������
void CountAndQuit();//��ʼԼɪ����Ϸ

int num = 0;//��¼��Ϸ������

int main()
{
	InputPerson();
	while (1)
	{
		ShowMenu();
		switch (choice)
		{
		case '0'://�˳�����
			printf("\n��лʹ�ã��ټ�\n");
			_getche();
			exit(0);
		case '1'://��ʾ����
			DisplayLink();
			break;
		case '2'://��ʾ����
			ResetPwd();
			break;
		case '3'://��ʼ��Ϸ
			CountAndQuit();
			break;
		default:
			printf("\nѡ�����\n");
		}
	}
}
void InputPerson()//�����������ʼ������
{
	Person* p;//�����ӵ���Ϸ��Ա
	char name[LEN + 1];//�������
	head = tail = NULL;
	while (1)
	{
		printf("�������%d���˵���Ϣ������%s������\n", num+1, OVER);
		printf("������������%d���ַ�����\t", LEN);
		scanf("%s", name);
		name[LEN] = '\0';
		if (strcmp(name, OVER) == 0)
		{
			return;
		}
		p = (Person*)malloc(sizeof(Person));
		strcpy(p->name, name);
		printf("���������루��������\t");
		scanf("%d", &p->pwd);
		//���½ڵ���뵽������
		p->next = head;//�½ڵ����ӵ�head
		if (NULL == head)
			head = tail = p;
		else
		{
			tail->next = p;
			tail = p;
		}
		num++;//��������
		printf("\n");
	}
}
void Line()
{
	printf("\n������������������������������������\n");
}
void ShowMenu()//��ʾ�˵������һ��choice
{
	while(1)
	{
		Line();
		printf("\t��ѡ�����:\n");
		printf("\t1����ʾ��Ϣ\n");
		printf("\t2����������ÿ��������\n");
		printf("\t3����ʼ��Ϸ\n");
		printf("\t0���˳���Ϸ\n");
		printf("\t��������ȷѡ�");
		choice=getche();
		if((choice-'0')>=0&&(choice-'0')<4)
			return;
	}
}
void DisplayLink()//��ʾ������Ϣ
{
		
	int i=0;
	Person *p=head;//��ͷ�ڵ㿪ʼ
	if(NULL==p)//���û�о���ֹ 
		return; 
	Line();
	printf("\n\t��ǰ������Ϣ���£�\n");
	printf("\t%2d:\t%s\t%d\n",++i,p->name,p->pwd);
	p=p->next;
	while(p!=head)
	{
		printf("\t%2d:\t%s\t%d\n",++i,p->name,p->pwd);
		p=p->next;
	}
	Line();
}
void ResetPwd()//��������
{
	int i=0;
	Person *p=head;//��ͷ�ڵ㿪ʼ
	if(NULL==p)//���û�о���ֹ 
		return; 
	Line();
	//�ȴ����һ��������
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
void CountAndQuit()//��ʼԼɪ����Ϸ
{
	int i,n,pwd;//����ѭ�����������������浱ǰ���� 
	//�ȸ�������
	Person *p,*c,*q;//�ֱ�ָ����ʱ��㣬������ĵ�ǰ��㣬��ǰ����ǰ���
	Person *head2,*tail2;//�ֱ�ָ���������ͷ��β���
	head2=tail2=NULL;
	c=head;
	//�׽ڵ㲻��ΪNULL
	if(NULL==head)
		return;
	//�ȸ���ͷ���
	p=(Person*)malloc(sizeof(Person));
	strcpy(p->name,c->name);
	p->pwd=c->pwd;
	p->next=p;
	head2=tail2=p;//����ɻ�
	//���������ڵ�
	c=c->next; 
	while(c!=head)
	{
		p=(Person*)malloc(sizeof(Person));
		strcpy(p->name,c->name);
		p->pwd=c->pwd;
		//���½ڵ���뵽�������� 
		p->next=head2;
		tail2->next=p;
		tail2=p;
		c=c->next;
	}
	//��ʼ��Ϸ
	Line();
	printf("\n\t��Ϸ�������£�\n"); 
	i=0;
	c=head2;//��ǰָ��ָ��������ͷ��� 
	q=tail2;//��ǰ�ڵ�ǰ�ڵ㣬ָ���������β���
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
		//��ǰָ��c��ָ�����˳�
		q->next=c->next;
		printf("\t��%d���˳��ߣ�%s\n",++i,c->name);
		pwd=c->pwd;//�˳���������Ϊ��һ������������ 
		free(c);
		c=q->next; 
	} 
	//���һ���˳�����
	 printf("\t��%d���˳��ߣ�%s",++i,c->name);
	 free(c);
	Line();
	
}

