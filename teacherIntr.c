#include<stdio.h>
#include<time.h>
#include<stdlib.h>

FILE *p,*q;
 typedef struct Quest{
 	
 	char t[100];
 	char a[20],b[20],c[20],d[20];
 	char answer[20];
}quest;

void easySet()
{
	int i;
	quest *d[10];
	for(i=0;i<10;i++)
		d[i]=(quest *)malloc(sizeof(quest));
	p = fopen("question1.bin","ab+");
	char c;
	for(i=0;i<10;i++)
	{
		printf("Question: ");
		getchar();
		gets(d[i]->t);
		printf("1. ");
		gets(d[i]->a);
		printf("2. ");
		gets(d[i]->b);
		printf("3. ");
		gets(d[i]->c);
		printf("4. ");
		gets(d[i]->d);
		scanf("%[^\n]s",d[i]->answer);
		fwrite(d[i],sizeof(quest),1,p);
		fseek(p,0,SEEK_END);
	}
	printf("Saving Question Paper...");
	Sleep(1000);
	system("cls");
	main();
}

void hardSet()
{
	int i;
	quest *d[10];
	for(i=0;i<10;i++)
		d[i]=(quest *)malloc(sizeof(quest));
	p = fopen("question2.bin","ab+");
	char c;
	for(i=0;i<10;i++)
	{
		printf("Question: ");
		getchar();
		gets(d[i]->t);
		printf("1. ");
		gets(d[i]->a);
		printf("2. ");
		gets(d[i]->b);
		printf("3. ");
		gets(d[i]->c);
		printf("4. ");
		gets(d[i]->d);
		scanf("%[^\n]s",d[i]->answer);
		fwrite(d[i],sizeof(quest),1,q);
		fseek(q,0,SEEK_END);
	}
	printf("Saving Question Paper...");
	Sleep(1000);
	system("cls");
	main();	
}

main()
{
	int ch;
	quest *d,*m;
	d = (quest*)malloc(sizeof(quest));
	
	
	printf("Student Test Portal\n1.Easy Set\n2.Hard Set\n3.EXIT\nSelect the set: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
			easySet();
			break;
		case 2:
			hardSet();
			break;
		case 3:
			printf("Logging Off...");
			Sleep(1000);
			exit(0);
		default:
			break;
	}
}
