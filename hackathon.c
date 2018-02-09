#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Data{
	char name[50];
	int admn,cia;
	char usn[20];
    }data;
	
void registration()
{	
	data *m,*c;
	FILE *p;
	p = fopen("admin.bin","ab+");
	c = (data*)malloc(sizeof(data));
	m = (data*)malloc(sizeof(data));
	printf("\n");
		
			a:printf("Enter the student's Admission Number and USN -\n");
			scanf("%d",&m->admn);
			if(m->admn==0)
			{
				printf("\t\t\t\t.....ABORTED!!!!\n\n");
				return;
				
			}
			fflush(stdin);
			scanf("%s",m->usn);
			rewind(p);
			for(;;)
			{
				fread(c,sizeof(data),1,p);
				if(feof(p))
				break;
			 	else if((m->admn==c->admn)||(strcmp(m->usn,c->usn)==0))
				{
				printf("\t\t\t\t\tALREADY REGISTERED..\n\n");
				goto a;
				}
			}
			printf("Enter student's name\n");
			fflush(stdin);
			gets(m->name);
			fwrite(m,sizeof(data),1,p);

		fclose(p);
		free(m);
		free(c);
printf("\n\t\t\t\t\t...DATABASE UPDATED SUCCESSFULLY...\n\n");
}

int signin()
{
	FILE *p;
	p = fopen("admin.bin","ab+");
	int flag=0;
	data *m,*c;
	m = (data*)malloc(sizeof(data));
	c = (data*)malloc(sizeof(data));
	
	again:printf("Enter your Login Id : ");
	scanf("%s",m->usn);
	printf("Enter your Password : ");
	scanf("%d",&m->admn);
	rewind(p);
	for(;;)
			{
				
				fread(c,sizeof(data),1,p);
				if(feof(p))
				break;
				
				else if((strcmp(m->usn,c->usn)!=0)||(m->admn!=c->admn))
				flag=1;
				else
				return(c->admn);
				
			}	
	if(flag==1)
	{
	printf("\t\t\t\t\tGive correct credentials....\n");
	goto again;
	
	}
}
void display()
{
	
	FILE *p;
	p = fopen("admin.bin","rb");
	data *w;
	w = (data*)malloc(sizeof(data));
	
	for(;;)
	{
		fread(w,sizeof(data),1,p);
		if(feof(p))
		break;
		else
		printf("%s\t%d\t%s\n\n",w->name,w->admn,w->usn);
	}
}
	
	
void test(int w)
{
	FILE *p;
	char usn[20];
	data *c;
	p  = fopen("admin.bin","rb+");
	c = (data*)malloc(sizeof(data));
	int choice,answer,score=0;
	printf("\t\t\tGet ready for Assignment test.....\n");
		Sleep(1000);
		system("cls");
		printf("Q1.what is 6+6?\n");
		printf("1.12\n2.16\n3.None of the above\n");
		scanf("%d",&answer);
		
		if(answer==1)
		score = 1;
		
		system("cls");
		printf("Q1.what is 7+7?\n");
		printf("1.12\n2.14\n3.None of the above\n");
		scanf("%d",&answer);	
		if(answer==2)
		score = 2;
		system("cls");
		printf("Your score out of 2 is %d",score);
		printf("\t\t\t\tThankyou for taking the test\n\n");
	
	for(;;)
	{
		fread(c,sizeof(data),1,p);
		if(feof(p))
		break;
		else if(w==c->admn)
		{
			c->cia = score;
			fseek(p,-(sizeof(data)),SEEK_CUR);
			fwrite(c,sizeof(data),1,p);
			fseek(p,(sizeof(data)),SEEK_CUR);
		}
	}	
	return;
}
main()
{
	int choice,choose,w;
	printf("\t\t\t\tWelcome To Student Portal\n\n");
	a:printf("1.Registration\t\t2.Sign In\t\t3.Display\t\t4.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{

		case 1:registration();
		break;
		
		case 2: w = signin();
		system("cls");
				printf("1.Tests\t\t2.Scores\t\t3.Bills\t\t4.Attendence\n");
				scanf("%d",&choose);
				switch(choose)
				{
					case 1:	test(w);
					break;
				//	case 2: display(w);
				//	break;
					
				}		
		break;
		
		case 3:display();
			break;
		case 4: 
		printf("Bye!\n");
		Sleep(2000);
		exit(0);
			
		
	}
  
goto a;
}
