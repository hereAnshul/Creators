#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>


int easy[10],hard[10];



 typedef struct Quest{
 	
 	char t[100];
 	char a[20],b[20],c[20],d[20];
 	char answer[20];
}quest;

main()
{
	int marks;
	char ans[20];
	int i;
	for (i=0;i<10;i++)
	{
		easy[i]=0;
		hard[i]=0;
	}
	
	int randomnumber;
    
	int count;    
	quest *m,*n;
	m =(quest*)malloc(sizeof(quest));
	n =(quest*)malloc(sizeof(quest));
	FILE *q,*w;
	int j=0,z=0;
	q = fopen("question1.bin","rb+");
	w = fopen("question2.bin","rb+");
	int flag = 0;
	/*fseek(q,0,SEEK_SET);
	for (;;)
	{
		
		fread(m,sizeof(quest),1,q);
		printf("%s\n",m->t);
		printf("%s\n",m->a);printf("%s\n",m->b);printf("%s\n",m->c);printf("%s\n",m->d);
		
	}*/
	//fread(m,sizeof(quest),1,q);
	//fread(n,sizeof(quest),1,w);
	
	int k;
	SYSTEMTIME start,end,time;
	
	
		while(count!=11)
		{
			
		
		
		/*srand(time(NULL));
		randomnumber = rand() % 10;
    	printf("%d\n", randomnumber);*/
    	
    	if(time.wSecond<10)
    	{
    		again:fread(m,sizeof(quest),1,q);
    		//srand(time(NULL));
    		//printf("%s",m->t);
			randomnumber = rand() % 10;
			randomnumber = randomnumber ;
    		//printf("%d\n", randomnumber);
    		
    		if(easy[randomnumber]==0)
    		{
    			
    			printf("%s\n",m->t);
				printf("%s\n",m->a);printf("%s\n",m->b);printf("%s\n",m->c);printf("%s\n",m->d);
				GetSystemTime(&start);
				gets(ans);
				if(strcmp(m->answer,ans)==0)
				{
					marks= marks +1 ;
					
				}
				GetSystemTime(&end);
				time.wSecond = end.wSecond - start.wSecond;
				//easy[randomnumber]=1;
				//fseek(q,0,SEEK_CUR);
				
				
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
			randomnumber = randomnumber ;
			//printf("%d",randomnumber);
    		//printf("%d\n", randomnumber);
    		
    		if(hard[randomnumber]==0)
    		{
    			
    			printf("%s\n",n->t);
				printf("%s\n",n->a);printf("%s\n",n->b);printf("%s\n",n->c);printf("%s\n",n->d);//printf("%s\n", m->answer);
				GetSystemTime(&start);
				gets(ans);
				if(strcmp(n->answer,ans)==0)
				{
					marks= marks +1 ;
					
				}
				GetSystemTime(&end);
				time.wSecond = end.wSecond - start.wSecond;
				hard[randomnumber]=1;
				fseek(w,0,SEEK_CUR);
				
				
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
    		if(count==10)
    		break;
    		j++;
		}	
			
		printf("Final Score: %d",marks);	

}

