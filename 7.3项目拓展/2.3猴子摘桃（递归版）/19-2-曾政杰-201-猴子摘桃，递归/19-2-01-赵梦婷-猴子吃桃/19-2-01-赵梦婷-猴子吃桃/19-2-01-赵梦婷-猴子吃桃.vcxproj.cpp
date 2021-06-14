#include<stdio.h>
#include<Windows.h>

void name();
int MonkeypeachA(int n, int k);//声明递归函数,吃桃子
int main()
{
	name();
	printf("请输入第几天剩下一个桃子：");
	int day;//天数
	scanf_s("%d", &day);//接收数据
	printf("第一天有%d个桃子\n", MonkeypeachA(0, day));//调用递归函数并且输出
	system("pause");
}
void name()
{
	printf("班级：软工2班\n姓名：曾政杰\n学号：201910414201\n");
	printf("拓展：1、用户指定第几天剩下一个桃子；\n ");
}
int MonkeypeachA(int n, int k)
{
	int c;//第i天
	if (n == k)
	{
		c=1;
	}
	else
	{
		c = (MonkeypeachA(n + 1, k) + 1) * (MonkeypeachA(n + 1, k) + 1);
	}
	return c;
}