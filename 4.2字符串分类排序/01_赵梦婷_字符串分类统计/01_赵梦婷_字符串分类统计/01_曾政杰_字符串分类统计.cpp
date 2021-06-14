#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include <conio.h>

#define LEN 100

void personalname();//个人信息
void count(char *str);//统计的函数
int main()
{
	personalname();
	int cc;
	printf("请输入需要内存大小\n");
	scanf_s("%d", &cc);  //输入字符数组的大小

	char* str = (char*)calloc(cc, sizeof(char));//动态申请指定大小的存储空间
	//char str[LEN + 1];
	
	printf("请输入字符串（长度不超过%d）\n",cc);
	printf("程序将按大小写字母、数字、空格和其他字符进行统计。\n");
	printf("如果超出%d个字符，程序将只对前%d个字符进行统计：\n",cc,cc);
	for (int i = 0; i < cc; i++)
	{
		scanf_s("%c", str+i);
		*(str + cc) = '\0';//最后强制加上结束符
	}
	//gets_s(str);
	//str[LEN] = '\0';
	count(str);
	system("pause");
}
void count(char *str)
{
	int lc = 0, uc = 0, d = 0, s = 0, o = 0;   //统计各类别字符计数器：小写、大写、数字、空格等
	int i = 0;
	
	while (*(str+i))
	{
		char c = *(str+i);
		if (c >= '0' && c <= '9')//单个字符的比较，统计数字字符
			d++;
		else if (c >= 'a' && c <= 'z') //单个字符的比较，统计小写字符
			lc++;
		else if (c >= 'A' && c <= 'Z')  //单个字符的比较，统计大写字符
			uc++;
		else if (c == ' ')   //单个字符的比较，统计空格
			s++;
		else
			o++;
		i++;
	}
	printf("数字有：%d\n小写字母：%d\n大写字母：%d\n空格：%d\n其他字符：%d\n",d,lc,uc,s,o);
}
void personalname()
{
	printf("班级：19软工2班\n姓名：曾政杰\n学号：201910414201\n");
	printf("本项目添加按照用户需求分配内存\n");
}