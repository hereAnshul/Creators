#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>

int marks=0;
typedef struct Quest
{
 	char t[100];
 	char a[20],b[20],c[20],d[20];
 	char answer[20];
}quest;

main()
{
	char ans[20];
	quest *m[10];
	int i;
	for(i=0;i<10;i++)
	{
		m[i] =(quest*)malloc(sizeof(quest));
	}
	FILE *q;

	q = fopen("question1.bin","rb");
	for(i=0;i<10;i++)
	{
		fread(m[i],sizeof(quest),1,q);
		printf("%s\n",m[i]->t);
		printf("%s\n",m[i]->a);printf("%s\n",m[i]->b);printf("%s\n",m[i]->c);printf("%s\n",m[i]->d);//printf("%s\n", m[i]->answer);
		gets(ans);
		
		if(strcmp(ans, m[i]->answer)==0)
		{
			printf("Correct!\n");
			marks=marks + 1;
		}
		else
		{
			printf("Wrong\n");
					
		}
	}
}
