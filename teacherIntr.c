#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int mark;
 typedef struct Quest{
 	
 	char t[100];
 	char a[20],b[20],c[20],d[20];
 	char answer[20];
}quest;

	void main()
{
	int i;
	quest *d,*m;
	d = (quest*)malloc(sizeof(quest));
	FILE *p,*o;
	p = fopen("question.bin","ab+");
	
	char c;
	printf("Enter questions and options and answer\n");
	for(i=0;i<1;i++)
	{
		printf("Question: ");
		gets(d->t);
		printf("1. ");
		gets(d->a);
		printf("2. ");
		gets(d->b);
		printf("3. ");
		gets(d->c);
		printf("4. ");
		gets(d->d);
		scanf("%s",d->answer);
		//strcpy(c,d->answer);
		fwrite(d,sizeof(quest),1,p);
		fseek(p,0,SEEK_END);
	}	
	
}
