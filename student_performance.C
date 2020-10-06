#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#define LEN sizeof(struct student)
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].pub,stu[i].sum
struct student/*����ѧ���ɼ��ṹ��*/
{ 
	int num;/*ѧ��*/
	char name[15];/*����*/
	double elec;/*ѡ�޿�*/
	double expe;/*ʵ���*/
	double requ;/*���޿�*/
	double pub;/*������*/ 
	double sum;/*�ܷ�*/
};
struct student stu[50];/*����ṹ������*/
void in();/*¼��ѧ���ɼ���Ϣ*/
void show();/*��ʾѧ����Ϣ*/
void order();/*���ܷ�����*/
void del();/*ɾ��ѧ���ɼ���Ϣ*/
void modify();/*�޸�ѧ���ɼ���Ϣ*/
void menu();/*���˵�*/
void insert();/*����ѧ����Ϣ*/
void total();/*����������*/
void searchNew();

 int main()/*������*/

{ 
	int n;
	menu();
	scanf("%d",&n);/*����ѡ���ܵı��*/
	while(n)
	{ 
		switch(n)
		{
		case 1: 
			in();
			break;
		case 2: 
			searchNew();
			break;
		case 3: 
			del();
			break;
		case 4:
			modify();
			break;
		case 5:
			insert();
			break;
		case 6:
			order();
			break;
		case 7:
			total();
			break;
		default:break;
		}
		getch();
		menu();/*ִ���깦���ٴ���ʾ�˵�����*/
		scanf("%d",&n);
	}
}

void in()/*¼��ѧ����Ϣ*/
{ 
	int i,m=0;/*m�Ǽ�¼������*/
	char ch[2];
	FILE *fp;/*�����ļ�ָ��*/
	if((fp=fopen("data","ab+"))==NULL)/*��ָ���ļ�*/
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(fp)) 
	{ 
		if(fread(&stu[m] ,LEN,1,fp)==1)
			m++;/*ͳ�Ƶ�ǰ��¼����*/
	}
	fclose(fp);
	if(m==0) 
		printf("�޼�¼!\n");
	else 
	{
		system("cls");
		show();/*����show��������ʾԭ����Ϣ*/
	}
	if((fp=fopen("data","wb"))==NULL)
	{ 
		printf("�޷��򿪴��ļ�\n");
		return;
	}
	for(i=0;i<m;i++) 
		fwrite(&stu[i] ,LEN,1,fp);/*��ָ���Ĵ����ļ�д����Ϣ*/
	printf("�Ƿ�����(y/n):");
	scanf("%s",ch);
	

	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ¼������Ϣ*/
	{
		printf("ѧ��:");
		scanf("%d",&stu[m].num);/*����ѧ��ѧ��*/
		for(i=0;i<m;i++)
			if(stu[i].num==stu[m].num)
			{
				printf("the number is existing,press any to continue!");
				getch();
				fclose(fp);
				return;
			}
			printf("����:");
			scanf("%s",stu[m].name);/*����ѧ������*/
			printf("ѡ�޿�:");
			scanf("%lf",&stu[m].elec);/*����ѡ�޿γɼ�*/
			printf("ʵ���:");
			scanf("%lf",&stu[m].expe);/*����ʵ��γɼ�*/
			printf("���޿�:");
			scanf("%lf",&stu[m].requ);/*������޿γɼ�*/
			printf("������:");
			scanf("%lf",&stu[m].pub);/*���빫���γɼ�*/
			stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ+stu[m].pub;/*������ܳɼ�*/
			if(fwrite(&stu[m],LEN,1,fp)!=1)/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
			{
				printf("�޷�¼��"); 
				getch(); 
			}
			else
			{ 
				printf("%s �ѱ��浵!\n",stu[m].name);
				m++;
			}
			printf("�Ƿ����¼��?(y/n):");/*ѯ���Ƿ����*/
			scanf("%s",ch);
	}
	fclose(fp);
	printf("OK!\n");
}

void show()
{
	FILE *fp;
	int i,m=0;
	fp=fopen("data","ab+");
	while(!feof(fp))
	{
		if(fread(&stu[m] ,LEN,1,fp)==1) 
			m++;
	}  
	fclose(fp);
	printf("ѧ��   ����          ѡ�޿�       ʵ���      ѡ�޿�     ������       �ܷ�\t\n");
	for(i=0;i<m;i++)
	{ 
		printf(FORMAT,DATA);/*����Ϣ��ָ����ʽ��ӡ*/
	}
}

void menu()/*�Զ��庯��ʵ�ֲ˵�����*/
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t|---------------------STUDENT-------------------|\n");
    printf("\t\t|---------------ѧ���ɼ�����ϵͳ----------------|\n");
	printf("\t\t|\t 0. exit                                |\n");
	printf("\t\t|\t 1. input record   ����ѧ���ɼ�         |\n");
	printf("\t\t|\t 2. search record  ��ѯѧ���ɼ�         |\n");
	printf("\t\t|\t 3. delete record  ɾ��ѧ���ɼ�         |\n");
	printf("\t\t|\t 4. modify record  �޸�ѧ���ɼ�         |\n");
	printf("\t\t|\t 5. insert record  ����ѧ���ɼ�         |\n");
	printf("\t\t|\t 6. order          ����ѧ���ɼ�         |\n");
	printf("\t\t|\t 7. number         ͳ��ѧ���ɼ�         |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\t��ѡ��(0-7):");
}

void order()/*�Զ���������*/
{ 
	FILE *fp;
	struct student t;
	int i=0,j=0,m=0;
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("can not open!\n");
		return;
	}
	while(!feof(fp)) 
		if(fread(&stu[m] ,LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0) 
		{
			printf("�޼�¼!\n");
			return;
		}
		for(i=0;i<m-1;i++)
			for(j=i+1;j<m;j++)/*˫��ѭ��ʵ�ֳɼ��Ƚϲ�����*/
				if(stu[i].sum<stu[j].sum)
				{ 
					t=stu[i];
					stu[i]=stu[j];
					stu[j]=t;
				}
				if((fp=fopen("data","wb"))==NULL)
				{ 
					printf("can not open\n");
					return;
				}
				for(i=0;i<m;i++)/*�������ź������������д��ָ���Ĵ����ļ���*/
					if(fwrite(&stu[i] ,LEN,1,fp)!=1)
					{ 
						printf("%s �޷���¼��!\n"); 
						getch();
					}
					fclose(fp);
					printf("����ɹ�\n");
	}
	             
void del()/*�Զ���ɾ������*/
{
	FILE *fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0) 
		{
			printf("�޼�¼!\n");
			return;
		}
		printf("������ѧ��:");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num)
				break;
		 if(i==m)
			{
			printf("���޴���");
			getchar();
			return;
			}
			printf("�ҵ���ѧ�����Ƿ�ɾ��?(y/n)");
			scanf("%s",ch);
			if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ����ɾ��*/
			{
				for(j=i;j<m;j++)
					stu[j]=stu[j+1];/*����һ����¼�Ƶ�ǰһ����¼��λ��*/
					m--;/*��¼���ܸ�����1*/
					printf("ɾ���ɹ�!\n");
				}
				if((fp=fopen("data","wb"))==NULL)
				{ 
					printf("�޷��򿪴��ļ�\n");
					return;
				}
				for(j=0;j<m;j++)/*�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���*/
					if(fwrite(&stu[j] ,LEN,1,fp)!=1)
					{ 
						printf("�޷���¼��!\n");
						getch();
					}
					fclose(fp);
				
}

void searchNew()  /*�Զ�����Һ���*/
{ 
double maxSum(double w,double x,double y,double z);
double minSum(double w,double x,double y,double z);
	FILE *fp;
	int snum,i,m=0;
	double max,min,avg;
	char ch[2];
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("�޷��򿪴��ļ�\n");
		return;
	}
	while(!feof(fp)) 
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
		fclose(fp);
		if(m==0)
		{
			printf("�޼�¼!\n");
			return;
		}
		printf("������ѧ��:");
		scanf("%d",&snum);
		
		for(i=0;i<m;i++)
			if(snum==stu[i].num)/*���������ѧ���Ƿ��ڼ�¼��*/
			{                                                 	
			    max=maxSum(stu[i].elec,stu[i].expe,stu[i].requ,stu[i].pub);/*�Ƚ����ſε��໥�ɼ��������߷֣���ͷ�*/
				min=minSum(stu[i].elec,stu[i].expe,stu[i].requ,stu[i].pub);
				avg=(stu[i].elec+stu[i].expe+stu[i].requ+stu[i].pub)/4;/*���ƽ����*/
		 	    printf("�ҵ�ѧ����Ϣ���Ƿ���ʾ?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
				{
					printf("ѧ��    ����      ѡ�޿�    ʵ���    ���޿�   ������   ��߷�  ��ͷ�  ƽ����   �ܷ�\t\n");
					printf("%d       %s       %5.1lf     %4.1lf    %7.1lf   %7.1lf  %6.1lf  %6.1lf  %6.1lf  %6.1lf" ,stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].pub,max,min,avg,stu[i].sum);
					

break;
				}
				else
					

return;
			}   
			if(i==m) 
				printf("���޴���!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/
}

double maxSum(double w,double x,double y,double z) /*������ֵ����*/
{
	double m,n,a;
	if(x>=y) 
		m=x;
	else m=y;
	if(m>=z)
		n=m;
	else n=z;
	if(n>=w)
	     a=n;
	else a=w;
	return(a);
}
double minSum(double w,double x,double y,double z) /*�����Сֵ����*/
{
	double m,n,a;
	if(x<=y) m=x;
	else m=y;
	if(m<=z) n=m;
	else n=z;
	if(n<=w) a=n;
	else a=w;
	return(a);
}



void modify()/*�Զ����޸ĺ���*/
{ 
	FILE *fp;
	int i,j,m=0,snum;
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("�޷��򿪴��ļ�\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;
		if(m==0)
		{
			printf("�޼�¼!\n");
			fclose(fp);
			return;
		}
		printf("�������޸�ѧ��ѧ�ţ�\n");
		scanf("%d",&snum);
		for(i=0;i<m;i++)
			if(snum==stu[i].num)/*������¼���Ƿ���Ҫ�޸ĵ���Ϣ*/
				break;
			if(i<m)
			{	
				printf("�ҵ���ѧ���������޸�!\n");
				printf("����:");
				scanf("%s",stu[i].name);/*��������*/
				printf("\nѡ�޿�:");
				scanf("%lf",&stu[i].elec);/*����ѡ�޿γɼ�*/
				printf("\nʵ���:");
				scanf("%lf",&stu[i].expe);/*����ʵ��γɼ�*/
				printf("\n���޿�:");
				scanf("%lf",&stu[i].requ);/*������޿γɼ�*/
				printf("\n������:");
			    scanf("%if",&stu[i].pub);/*���빫���γɼ�*/
			    stu[i].sum=stu[i].elec+stu[i].expe+stu[i].requ+stu[i].pub;
				printf("�ɼ����޸�") ;
			}
			else 
			{
				printf("�޷��ҵ�����!");
				getchar();
				return;
			}
			if((fp=fopen("data","wb"))==NULL)
			{
				printf("�޷��򿪴��ļ�\n");
				return;
			}
			for(j=0;j<m;j++)/*�����޸ĵ���Ϣд��ָ���Ĵ����ļ���*/
				if(fwrite(&stu[j] ,LEN,1,fp)!=1)
				{ 
					printf("�޷�¼��!"); 
					getch(); 
				}
				fclose(fp);
}

void insert()/*�Զ�����뺯��*/
{ 
	FILE *fp;
	int i,j,k,m=0,snum;
	if((fp=fopen("data","ab+"))==NULL)
	{ 
		printf("�޷��򿪴��ļ�\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1)
			m++;
		if(m==0) 
		{
			printf("�޼�¼!\n");
			fclose(fp);
			return;
		}
		printf("��������������λ��\n");
		scanf("%d",&snum);/*����Ҫ�����λ��*/
		for(i=0;i<m;i++)
			if(snum==stu[i].num)
				break;
			for(j=m-1;j>i;j--)
				stu[j+1]=stu[j];/*�����һ����¼��ʼ�������һλ*/
			printf("����������Ϣ:\n");
			printf("ѧ��:");
			scanf("%d",&stu[i+1].num);
			for(k=0;k<m;k++)
				if(stu[k].num==stu[i+1].num&&k!=i+1)
				{
					printf("��ѧ���Ѵ��ڣ���������˳�!");
					getch();
					fclose(fp);
					return;
				}	
				printf("����:\n");
				scanf("%s",stu[i+1].name);
				printf("\nѡ�޿�:");
				scanf("%lf",&stu[i+1].elec);
				printf("\nʵ���:");
				scanf("%lf",&stu[i+1].expe);
				printf("\n���޿�:");
				scanf("%lf",&stu[i+1].requ);
			    printf("\n������:");
			    scanf("%lf",&stu[i+1].pub);/*���빫���γɼ�*/
			    stu[i+1].sum=stu[i+1].elec+stu[i+1].expe+stu[i+1].requ+stu[i+1].pub;
				if((fp=fopen("data","wb"))==NULL)
				{ 
					printf("�޷��򿪴��ļ�\n");
					return;
				}
				for(k=0;k<=m;k++)
					if(fwrite(&stu[k] ,LEN,1,fp)!=1)/*���޸ĺ�ļ�¼д������ļ���*/
					{
						printf("�޷�¼��!"); 
						getch(); 
					}
					fclose(fp);
}

void total()
{ 
	FILE *fp;
	int m=0;
	if((fp=fopen("data","ab+"))==NULL)
	{         
		printf("�޷��򿪴��ļ�\n");
		return;
	}
	while(!feof(fp))  
		if(fread(&stu[m],LEN,1,fp)==1) 
			m++;/*ͳ�Ƽ�¼������ѧ������*/
		if(m==0)
		{
			printf("�޼�¼!\n");
			fclose(fp);
			return;
		}
		printf("������ %d ��ѧ��!\n",m);/*��ͳ�Ƶĸ������*/
		fclose(fp);
}