#include<stdio.h>

void name();
int fac(int n);//声明阶乘的函数
int main()
{
	name();
	printf("请输入需要阶乘的数字");
	int n;//需要阶乘的数
	scanf_s("%d", &n);//输入该数
	printf("%d!=%d", n, fac(n));//调用fac函数并且输出

}
void name()
{
	printf("班级：软工2班\n姓名：曾政杰\n学号：201910414201\n");
}
int fac(int n)
{
	if (n == 0)
		return 1;//递归终结条件
	else
		return n * fac(n - 1);//递归调用函数自身
}