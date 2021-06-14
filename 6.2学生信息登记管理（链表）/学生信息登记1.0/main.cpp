//�궨����  
#define  _CRT_SECURE_NO_DEPRECATE    
  
  
//ͷ�ļ���  
#include<stdio.h>   
#include<stdlib.h>
#include<conio.h>
#include<string.h>   
#include<Windows.h>   
  
  
//ȫ�ֱ�����  
//ѧ���ṹ��  
typedef  struct  tagStudent  
{  
    char            Num[10];                    //ѧ��  
    char             Name[20];              //����                                          
    double      Regular_Score;      //ƽʱ�ɼ�  
    double      Final_Score;            //��ĩ�ɼ�  
    double     Total_Score;             //�����ɼ�  
  
}Student;  
  
//ѧ��������  
typedef  struct  tagNode  
{  
    Student  Stu;                       //������ѧ����Ϣ  
    struct  tagNode*  pNext;        //ָ����ָ����һ��ѧ�����  
  
}Node;  
  
//��������ĵ�һ��ѧ������ѧ���������ͷ���  
Node  *g_pHead = NULL;  
  
  
//ȫ�ֺ���������  
// ��ӡ���ܲ˵�  
void  Print_Menu();  
//1¼��ѧ����Ϣ  
void  Enter_Students();  
//2��ѯѧ����Ϣ  
Node*  Inquire_Students();  
//3��ʾѧ����Ϣ  
void  Display_Students();  
//4ɾ��ѧ����Ϣ  
void  Deleting_Students();  
//5�޸�ѧ����Ϣ  
void  Amend_Students();  
//6������Ϣչʾ
void personalname(); 
  
  
//����������������������  
int main()  
{  
    while (1)//��ѭ��  
    {  
        //����  
        system("CLS");  
        //��ӡ���ܲ˵�  
        Print_Menu();  
        char  ch;  
        //����̨�޻��Ի�ȡ��Ϣ  
        ch = _getch();  
        //switch��֧ѡ��ṹ  
        switch (ch)  
        {  
        case'1':  
            //1¼��ѧ����Ϣ  
            Enter_Students();  
            break;  
        case'2':  
            //2��ѯѧ����Ϣ  
        {  
            Node *pNode = Inquire_Students();  
            if (pNode != NULL)  
            {  
                printf("%s\t %s\t %0.2lf \t%0.2lf \t%0.2lf\t\n",  
                    pNode->Stu.Num,                  //ѧ��  
                    pNode->Stu.Name,                 //����  
                    pNode->Stu.Regular_Score,    //ƽʱ�ɼ�  
                    pNode->Stu.Final_Score,      //��ĩ�ɼ�  
                    pNode->Stu.Total_Score); //�����ɼ�  
            }  
            else  
            {  
                printf("δ�ҵ�ѧ����Ϣ����ȷ��ѧ����Ϣ��\n");  
            }  
            break;  
        }                 
        case'3':  
            //3��ʾѧ����Ϣ  
            Display_Students();  
            break;  
        case'4':  
            //4ɾ��ѧ����Ϣ  
            Deleting_Students();  
            break;  
        case'5':  
            //5�޸�ѧ����Ϣ  
            Amend_Students();  
            break;    
        case'0':  
            //�˳�����ϵͳ  
            printf("��ӭ�ٴ�ʹ�ã�\n");  
            return 0;  
            break;  
        default:  
            //����Ľ�׳�ԣ��Ѻ���ʾ  
            printf("�������ѡ���д���������ѡ���ܣ�\n");  
            break;  
        }  
        system("PAUSE");  
    }  
  
    return 0;  
}  
  
  
//ȫ�ֺ���ʵ����  
// ��ӡ���ܲ˵�  
void  Print_Menu()  
{  
    //����  
    system("CLS");  
    personalname();
    printf("=================================================\n");  
    printf("===================��ѡ���Ӧ����================\n");  
    printf("=================================================\n");  
    printf("=\t\t1��¼��ѧ����Ϣ\t\t\t=\n");  
    printf("=\t\t2����ѯѧ����Ϣ\t\t\t=\n");  
    printf("=\t\t3����ʾѧ����Ϣ\t\t\t=\n");  
    printf("=\t\t4��ɾ��ѧ����Ϣ\t\t\t=\n");  
    printf("=\t\t5���޸�ѧ����Ϣ\t\t\t=\n");  
    printf("=\t\t0���˳�����ϵͳ\t\t\t=\n");  
    printf("=================================================\n");  
  
    return;  
}  

//1¼��ѧ����Ϣ  
void  Enter_Students()  
{  
    //����  
    system("CLS");  
    printf("=================================================\n");  
    printf("===============��ӭʹ�ø�Уѧ������ϵͳ==========\n");  
    printf("=================================================\n");  
    printf("===================¼��ѧ����Ϣ����================\n");  
    printf("=================================================\n");  
    printf("\n����������ѧ����Ϣ:\n\n|ѧ�� \t|����   |ƽʱ�ɼ�|  |��ĩ�ɼ�|  |�����ɼ�|\n");  
  
    //���嵥�����һ����㣺��ǰ���  
    Node *p;  
  
    //��ͷ������ǰ���  
    p = g_pHead;  
  
    //�ڲ����½��ǰ�ҵ�β��㣬  
    while (g_pHead != NULL && p->pNext != NULL)  
    {  
        p = p->pNext;  
    }  
  
    //Ϊ�µ�ѧ��Ԫ�ط���һ���ռ�  
    //mallac  void*  ������   ǿ������ת��  
    Node* pNewNode = (Node*)malloc(sizeof(Node));  
    pNewNode->pNext = NULL;  
  
    //���½ڵ����β��������Ϊͷ���  
    if (g_pHead == NULL)  
    {  
        g_pHead = pNewNode;  
        p = g_pHead;  
    }  
    else  
    {  
        //p����һ���ڵ�ΪpNewNode  
        p->pNext = pNewNode;  
    }  
  
    //�����µ�ѧ��������Ϣ  
    scanf("%s %s %lf %lf %lf", pNewNode->Stu.Num,        //ѧ��  ���������������׵�ַ  
        pNewNode->Stu.Name,                  //����  
        &pNewNode->Stu.Regular_Score,    //ƽʱ�ɼ�  
        &pNewNode->Stu.Final_Score,      //��ĩ�ɼ�  
        &pNewNode->Stu.Total_Score); //�����ɼ�  
  
    printf("\nѧ����Ϣ¼��ϵͳ�ɹ���\n");  
    return;  
}  
  
//2��ѯѧ����Ϣ  
Node *Inquire_Students()  
{  
    //����  
    system("CLS");  
    printf("=================================================\n");  
    printf("===============��ӭʹ�ø�Уѧ������ϵͳ==========\n");  
    printf("=================================================\n");  
    printf("===================��ѯѧ����Ϣ����================\n");  
    printf("=================================================\n");  
    char      Num[10];  //ѧ��  
  
    printf("\n��������Ҫ��ѯѧ����ѧ�ţ�\n");  
  
    scanf("%s",Num);  
  
    Node  *p = g_pHead;  
    printf("\nѧ��\t����\tƽʱ�ɼ�\t��ĩ�ɼ�\t�����ɼ�\t\n");  
  
    //��������  
    while (p != NULL)  
    {         
          
        int  ptr = _stricmp(p->Stu.Num , Num);  
        //����ҵ�ѧ����Ϣ  
        if (ptr  ==  0)  
        {  
                return  p;  
        }  
            //��������ң�ֱ�������������˳�while  
            p = p->pNext;      
    }  
  
    //������û���ҵ�ѧ����Ϣ  
    if (p == NULL)  
    {             
        return  NULL;  
    }     
      
    return  NULL;  
}  
  
//3��ʾѧ����Ϣ  
void  Display_Students()  
{  
    //����  
    system("CLS");  
    printf("=================================================\n");  
    printf("===============��ӭʹ�ø�Уѧ������ϵͳ==========\n");  
    printf("=================================================\n");  
    printf("===================��ʾѧ����Ϣ����================\n");  
    printf("=================================================\n");  
  
    Node  *p = g_pHead;  
    printf("ѧ��\t| ����\t| ƽʱ�ɼ�\t| ��ĩ�ɼ�\t| �����ɼ�\t|\n");  
  
    //���������û��ѧ����Ϣ  
    if (p == NULL)  
    {  
        printf("δ�ҵ�ѧ����Ϣ������¼��ѧ����Ϣ��\n\n");  
        return;  
    }  
  
    //�����������ѧ����Ϣ�����������  
    while (p != NULL)  
    {         
        printf("%s\t|  %s\t|  %0.2lf \t| %0.2lf \t| %0.2lf\t|\n",  
                    p->Stu.Num,                  //ѧ��  
                    p->Stu.Name,                 //����  
                    p->Stu.Regular_Score,    //ƽʱ�ɼ�  
                    p->Stu.Final_Score,      //��ĩ�ɼ�  
                    p->Stu.Total_Score); //�����ɼ�);  
  
        p = p->pNext;  
  
    }  
    printf("=================================================\n");  
    return;  
}  
  
//4ɾ��ѧ����Ϣ  
void  Deleting_Students()  
{  
    //����  
    system("CLS");  
    printf("=================================================\n");  
    printf("===============��ӭʹ�ø�Уѧ������ϵͳ==========\n");  
    printf("=================================================\n");  
    printf("===================ɾ��ѧ����Ϣ����================\n");  
    printf("=================================================\n");  
    char      Num[10];  //ѧ��  
  
    printf("\n��������Ҫɾ��ѧ����ѧ�ţ�\n");  
  
    scanf("%s", Num);  
  
    Node  *p = g_pHead;  
  
    //����һ����ʱ�������  
    Node  *p2 = NULL;  
  
    //���Ҫɾ����ѧ����Ϣ�������ͷ���  
    int  ptr = _stricmp(g_pHead->Stu.Num , Num);  
    if (ptr  ==  0)  
    {  
        p2 = g_pHead;  
        g_pHead = g_pHead->pNext;  
        //�ͷ��ڴ棬ɾ����Ϣ  
        free(p2);  
        printf("ɾ��ѧ����Ϣ�ɹ���");  
        return;  
    }  
      
    //ɾ����ѧ����Ϣ����ͷ���  
    while (p->pNext  !=  NULL)  
    {  
        int  ptr = _stricmp(p->pNext->Stu.Num, Num);  
        if (ptr  ==  0)  
        {  
            p2 = p->pNext;  
            p->pNext = p->pNext->pNext;  
            //�ͷ��ڴ棬ɾ����Ϣ  
            free(p2);         
            printf("ɾ��ѧ����Ϣ�ɹ���");  
            return;  
        }  
        if (ptr != 0)  
        {  
            printf("ѧ����Ϣ����ȷ����ȷ��ѧ����Ϣ��");       
        }  
        //��������  
        p = p->pNext;  
    }  
    //������û���ҵ�ѧ����Ϣ  
    if (p == NULL)  
    {  
        printf("δ�ҵ�ѧ����Ϣ����ȷ��ѧ����Ϣ��\n\n");       
    }  
  
    return;  
}  
  
//5�޸�ѧ����Ϣ  
void  Amend_Students()  
{  
    //����  
    system("CLS");  
    printf("=================================================\n");  
    printf("===============��ӭʹ�ø�Уѧ������ϵͳ==========\n");  
    printf("=================================================\n");  
    printf("===================�޸�ѧ����Ϣ����================\n");  
    printf("=================================================\n");  
  
    char      Num[10];  //ѧ��  
  
    printf("\n��������Ҫ�޸�ѧ����ѧ�ţ�");  
  
    scanf("%s", Num);  
  
    Node  *p = g_pHead;  
  
    //��������  
    while (p != NULL)  
    {  
        int  ptr = _stricmp(p->Stu.Num, Num);  
        if (ptr  ==  0)  
        {  
            //��ʾҪ�޸�ѧ����Ϣ  
            printf("=================================================\n");  
            printf("%s\t|  %s\t|  %0.2lf \t| %0.2lf \t| %0.2lf\t|\n",  
                p->Stu.Num,                  //ѧ��  
                p->Stu.Name,                 //����  
                p->Stu.Regular_Score,    //ƽʱ�ɼ�  
                p->Stu.Final_Score,      //��ĩ�ɼ�  
                p->Stu.Total_Score); //�����ɼ�);  
            printf("=================================================\n");  
            printf("���޸�ѧ����Ϣ\n\n");  
            printf("ѧ��\t����\tƽʱ�ɼ�\t��ĩ�ɼ�\t�����ɼ�\t\n");  
            scanf("%s %s %lf %lf %lf",  
                p->Stu.Num,                  //ѧ��  
                p->Stu.Name,                 //����  
                &p->Stu.Regular_Score,   //ƽʱ�ɼ�  
                &p->Stu.Final_Score,     //��ĩ�ɼ�  
                &p->Stu.Total_Score);    //�����ɼ�  
            printf("�޸�ѧ����Ϣ�ɹ���\n");  
            break;  
        }     
        //��������  
        p = p->pNext;  
    }  
    //������û���ҵ�ѧ����Ϣ  
    if (p == NULL)  
    {  
        printf("δ�ҵ�ѧ����Ϣ����ȷ��ѧ����Ϣ��\n\n");   
    }  
  
    return;  
}  
void personalname()
{
	printf("�༶��19��2��\n������������\nѧ�ţ�201910414201\n");
	printf("����Ŀ������ʵ��ѧ����Ϣ��¼�룬��չ��ѧ����Ϣ��ɾ�����޸Ĺ���\n");
}
