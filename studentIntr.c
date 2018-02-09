#include<stdio.h>
#include<time.h>
#include<stdlib.h>

 typedef struct Quest{
 	
 	char t[100];
 	char a[20],b[20],c[20],d[20];
 	char answer[20];
}quest;

main()
{
	char ans[20];
	quest *m;
	int i;
	m =(quest*)malloc(sizeof(quest));
	FILE *q;
	q = fopen("question.bin","ab+");
	
		fread(m,sizeof(quest),1,q);
		printf("%s\n",m->t);
		printf("%s\n",m->a);printf("%s\n",m->b);printf("%s\n",m->c);printf("%s\n",m->d);printf("%s\n", m->answer);
		gets(ans);
		
		if(strcmp(ans, m->answer)==0)
			printf("Maa Chod Di!\n");
		else
			printf("Aee Chutiya\n");		

}

