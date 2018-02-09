#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>


int easy[10],hard[10];
int count;


 typedef struct Quest{
 	
 	char t[100];
 	char a[20],b[20],c[20],d[20];
 	char answer[20];
}quest;

main()
{
	
	char ans[20];
	int i;
	for (i=0;i<10;i++)
	{
		easy[i]=0;
		hard[i]=0;
	}
	
	
	int randomnumber;
    
    
	quest *m,*n;
	m =(quest*)malloc(sizeof(quest));
	n =(quest*)malloc(sizeof(quest));
	FILE *q,*w;
	int j=0,z=0;
	q = fopen("question1.bin","rb+");
	w = fopen("question2.bin","rb+");
	int flag = 0;
	fread(m,sizeof(quest),1,q);
	fread(n,sizeof(quest),1,w);
	
	int k,count;
	SYSTEMTIME start,end,time;
	
	
		while(count<11)
		{
			
		
		
		/*srand(time(NULL));
		randomnumber = rand() % 10;
    	printf("%d\n", randomnumber);*/
    	
    	if(time.wSecond<10)
    	{
    		again:fread(m,sizeof(quest),1,q);
    		//srand(time(NULL));
			randomnumber = rand() % 10;
    		//printf("%d\n", randomnumber);
    		
    		if(easy[randomnumber]==0)
    		{
    			
    			printf("%s\n",m->t);
				printf("%s\n",m->a);printf("%s\n",m->b);printf("%s\n",m->c);printf("%s\n",m->d);//printf("%s\n", m->answer);
				GetSystemTime(&start);
				gets(ans);
				GetSystemTime(&end);
				time.wSecond = end.wSecond - start.wSecond;
				easy[randomnumber]=1;
				
			}
			else
			{
				for(z=0;z<11;z++)
				{	
					if(easy[z]==0)
					{
						goto again;
						
					}
					
				}
			
			}
		
    			
			}
			
			if(time.wSecond>10)
    	{
    		agains:fread(n,sizeof(quest),1,w);
    		//srand(time(NULL));
			randomnumber = rand() % 10;
    		//printf("%d\n", randomnumber);
    		
    		if(hard[randomnumber]==0)
    		{
    			
    			printf("%s\n",n->t);
				printf("%s\n",n->a);printf("%s\n",n->b);printf("%s\n",n->c);printf("%s\n",n->d);//printf("%s\n", m->answer);
				GetSystemTime(&start);
				gets(ans);
				GetSystemTime(&end);
				time.wSecond = end.wSecond - start.wSecond;
				hard[randomnumber]=1;
				
			}
			else
			{
				for(z=0;z<11;z++)
				{	
					if(hard[z]==0)
					{
						goto agains;
						
					}
					
				}
			
			}
		
    			
			}
    		
    		count++;
    		j++;
		}
    	
    
		/*fread(m,sizeof(quest),1,q);
		if(feof(q))
		break;
		else if
		{
			if((j==randomnumber+1)&&()
		}
		//printf("%s\n",m->t);
		//printf("%s\n",m->a);printf("%s\n",m->b);printf("%s\n",m->c);printf("%s\n",m->d);printf("%s\n", m->answer);
		//gets(ans);
		j++;
		}
		
	/*	if(strcmp(ans, m->answer)==0)
			printf("Maa Chod Di!\n");
		else
			printf("Aee Chutiya\n");*/		

}

