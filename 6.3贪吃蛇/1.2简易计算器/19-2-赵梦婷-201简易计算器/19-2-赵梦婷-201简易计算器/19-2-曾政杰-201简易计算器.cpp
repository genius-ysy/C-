#include<stdio.h>
#include<Windows.h>
#include<math.h>

void menu();//自定义菜单，避免了输入字符+、-、*、/
void normal(int c);
void sqrt();
void power();
int main()
{
	printf("班级：19软工2班\n姓名：曾政杰\n学号：201910414201\n");
	printf("本项目增加求单个数平方根（保留两位小数）和求一个数的n次幂");
	menu();
	int c;//存放需要计算的类型
	scanf_s("%d", &c);
	if (c < 5)
		normal(c);
	else if (c == 5)
		sqrt();
	else if (c == 6)
		power();
	system("pause");
	return 0;
}
void normal(int c)
{
	double a, b;//存放需要计算的数字
	scanf_s("%lf%lf", &a, &b);
	switch (c)
	{
	case 1:
		printf("%.2lf+%.2lf=%.2lf", a, b, a + b); break;
	case 2:
		printf("%.2lf-%.2lf=%.2lf", a, b, a - b); break;
	case 3:
		printf("%.2lf*%.2lf=%.2lf", a, b, a * b); break;
	case 4:
		if (b == 0)
		{
			printf("输入错误，除数不能为0");
			break;
		}
		else
			printf("%.2lf/%.2lf=%.2lf", a, b, a / b); break;
	}
}
void menu()//自定义菜单，避免了输入字符+、-、*、/
{
	printf("输入下列数字，选择需要计算的类型\n");
	printf("  1、 + \n");
	printf("  2、 - \n");
	printf("  3、 * \n");
	printf("  4、 / \n");
	printf("  5、 开方 \n");
	printf("  6、 求一个数的n次幂 \n");
	printf("请输入需要计算的类型，再输入数字\n请输入计算类型:");
}
void sqrt()
{
	float a;
	scanf_s("%f", &a);
	printf("%.2f开方结果是%.2f", a, sqrt(a));//调用sqrt函数开方
}
void power()
{
	printf("请依次输入底数和指数（中间用空格隔开,指数必须为正整数）");
	float a, t = 1;//底数
	int b;//指数
	scanf_s("%f%d", &a, &b);
	for (int i = 0; i < b; i++)
	{
		t *= a;//计算
	}
	printf("  %.2f^%d=%.2f", a, b, t);
}