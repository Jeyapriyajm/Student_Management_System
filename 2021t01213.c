//---Header files----//
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
//---structures---//
struct course 
{
	char c_name[20];
	char grade;
	float c_value;
};
struct student
{
	char name[20];
	char index[20];
	char dep[20];
	struct course c[10];
	int c_count;
	float total;
	float gpa;
};
struct c{
	char name[20];
	char id[10];
	
};

void add();
void course_details();
void display();
void display_c_details();
void grade();
void update();
void search();
int main()
{
	int n;
	system("COLOR B");
	system("cls");
	choice:
	
	
	printf("\n\n\t\t\t==============================="
					 "===============================\n");
	printf(  "\t\t\t                              STUDENT\n");
	printf(  "\t\t\t                         MANAGEMENT SYSTEM\n");
			
	printf(    "\t\t\t==============================="
			         "===============================\n\n\n");
	
	printf("\n\t\t\t    01.  ADD NEW STUDENT DETAILS ");
	printf("\n\t\t\t    02.  ADD NEW COURSE DETAILS ");
	printf("\n\t\t\t    03.  DISPLAY STUDENT DETAILS ");
	printf("\n\t\t\t    04.  DISPLAY COURSE  DETAILS ");
	printf("\n\t\t\t    05.  UPDATE STUDENT DETAILS ");
	printf("\n\t\t\t    06.  SURCH EACH STUDENT DETAILS ");
	printf("\n\t\t\t    07.  EXIT THE ENTIRE PROGRAM ");
	
	do{
		
		printf("\n\n\n\tENTER THE PATH  :");
		scanf("%d",&n);
		switch(n){
			case 1:
				add();
				goto choice;
				break;
				
			case 2:
				course_details();
				goto choice;
				break;
			case 3:
				display();
				goto choice;
				break;
			case 4:
				display_c_details();
				goto choice;
				break;
			case 5:
				update();
				goto choice;
				break;
			case 6:
				search();
				goto choice;
				break;
			
		}
		
	}while(n>=1&&n<7);
}
void add()
{
	system("cls");
	int a;
	FILE *fp;
	
	fp=fopen("student.txt","a");
	if(fp == NULL)
	{
      printf("Error!");   
      exit(1);             
	}
	
	struct student s;
	
	
	do {
		s.gpa=0;
		s.total=0;
		float k[5]={4.0,3.0,2.5,1.5,0};
		system("COLOR E");
		printf("\n\n\n\t------------ADD STUDENT DETAILS----------\n\n");
		printf("\n\t ENTER THE NAME           :  ");
		scanf("%s",s.name);
		printf("\t ENTER THE INDEX NUMBER   :  ");
		scanf("%s",s.index);
		printf("\t ENTER THE DEPARTMENT     :  ");
		scanf("%s",s.dep);
		fflush(stdin);
		printf("\t ENTER THE COURSE COUNT   :  ");
		scanf("%d",&s.c_count);
		for(int  i=0;i<s.c_count;i++)
		{
			printf("\t\t\t ENTER COURSE NAME  :  ");
			scanf("%s",s.c[i].c_name);
			fflush(stdin);
			printf("\t\t\t ENTER COURSE GRADE  :  ");
			scanf("%c",&s.c[i].grade);
			if(s.c[i].grade=='a')
			{
				s.c[i].c_value=k[0];
				s.total+=s.c[i].c_value;
			}
			
			else if(s.c[i].grade=='A')
			{
				s.c[i].c_value=k[0];
				s.total+=s.c[i].c_value;
				
			}
			else if(s.c[i].grade=='B')
			{
				s.c[i].c_value=k[1];
				s.total+=s.c[i].c_value;
				
			}
			else if(s.c[i].grade=='b')
			{
				s.c[i].c_value=k[1];
				s.total+=s.c[i].c_value;
			}
			else if(s.c[i].grade=='C')
			{
				s.c[i].c_value=k[2];
				s.total+=s.c[i].c_value;
			}
			else if(s.c[i].grade=='c')
			{
				s.c[i].c_value=k[2];
				s.total+=s.c[i].c_value;
			}
			else if(s.c[i].grade=='D')
			{
				s.c[i].c_value=k[3];
				s.total+=s.c[i].c_value;
			}
			else if(s.c[i].grade=='d')
			{
				s.c[i].c_value=k[3];
				s.total+=s.c[i].c_value;
			}
			else if(s.c[i].grade=='E')
			{
				s.c[i].c_value=k[4];
				s.total+=s.c[i].c_value;
			}
			else if(s.c[i].grade=='e')
			{
				s.c[i].c_value=k[4];
				s.total+=s.c[i].c_value;
			}
			
		}
		
		s.gpa=s.total/(float)s.c_count;
		fwrite(&s,sizeof(struct student),1,fp);
		printf("\n(press 1 to add another student details"
		         "\n or press 0   : ");
		scanf("%d",&a);
		
		
	}while(a!=0);
	fclose(fp);
	
}
void course_details()
{
	system("cls");
	int a;
	FILE *fp1;
	fp1=fopen("course.txt","a");
	if(fp1 == NULL)
	{
      printf("Error!");   
      exit(1);             
	}
	struct c c1;
	
	
	do {
		system("cls");
		system("COLOR C");
		printf("\n\n\n\t\t-------------ADD COURSE DETAILS------------\n\n");
		
		printf("\t\t ENTER THE COURSE NAME   :  ");
		scanf("%s",c1.name);
		printf("\t\t ENTER THE COURSE ID     :  ");
		scanf("%s",c1.id);
		fwrite(&c1,sizeof(struct c),1,fp1);
		printf("\n\n press 1 to add another student\n"
				" press 0 to exit  :  ");
		scanf("%d",&a);
		
	}while(a!=0);
	fclose(fp1);
	
}

void display()
{
	
	system("cls");
	
	FILE *fp;
	struct student s;
	fp=fopen("student.txt","r");
	if(fp == NULL)
	{
      printf("Error!");   
      exit(1);             
	}
	printf("\n\t\t\t------------------");
	printf("\n\t\t\t\tStudent Report");
	printf("\n\t\t\t------------------");
	while(fread(&s,sizeof(struct student),1,fp))
	{
		system("COLOR D");
		printf("\n\t _________________________________________");
		printf("\n\n\t   --------STUDENT DETAILS----------  ");
		printf("\n\n\t  STUDENT NAME :-  %s",s.name);
		printf("\n\t  DEPARTMENT   :-  %s",s.dep);
		printf("\n\t  INDEX NUMBER :-  %s",s.index);
		printf("\n");
		printf("\n\n\t            COURSE DETAILS      ");
		for(int i=0;i< s.c_count;i++)
		{
			printf("\n\n\t COURSE  NAME  :-  %s",s.c[i].c_name);
			printf("\n\t COURSE  GRADE :-  %c",s.c[i].grade);
			printf("\n\t CREDIT VALUE  :-  %.2f\n",s.c[i].c_value);
		}
		printf("\n\n\t GPA OF THE STUDENT :-  %.2f",s.gpa);
		printf("\n\t _________________________________________");
		
	}
	fclose(fp);
	
}


void display_c_details()
{
	system("cls");
	int a;
	FILE *fp1;
	fp1=fopen("course.txt","r");
	if(fp1 == NULL)
	{
      printf("Error!");   
      exit(1);             
	}
	struct c c1;
	while(fread(&c1,sizeof(struct c),1,fp1))
	{
		system("COLOR 3");
		printf("\n\t _______________________________________________");
		printf("\n\n\t     -----COURSE DETAILS------\n");
		printf("\n\tCOURSE NAME   :     %s",c1.name);
		printf("\n\tCOURSE ID     :     %s\n",c1.id);
		printf("\n\t |---------------------------------------|");
		printf("\n\t |    GRADE                CREDIT VALUE  |");
		printf("\n\t |_______________________________________|");
		printf("\n\t |        A                       4.0    |");
		printf("\n\t |        B                       3.0    |");
		printf("\n\t |        C                       2.5    |");
		printf("\n\t |        D                       1.5    |");
		printf("\n\t |        E                        0     |");
		printf("\n\t |_______________________________________|");
		printf("\n\t _______________________________________________");
		

	}
	fclose(fp1);
}
void update()
{
	system("cls");
	system("COLOR B");	
	FILE *fp,*temp;
	char temp_idex[10];
	struct student s;
	int found=0;
	fp=fopen("student.txt","r+");
	temp=fopen("temp.txt","a+");
	if(fp == NULL)
	{
	  printf("Error!");   
	  exit(1);             
	}
	printf("\nENTER STUDENT INDEX NUMBER  :");
	scanf("%s",temp_idex);

	while(fread(&s,sizeof(struct student),1,fp))
	{
		if(strcmp(temp_idex,s.index)!=0)
		{
			fwrite(&s,sizeof(struct student),1,temp);
		}
		else if(strcmp(temp_idex,s.index)==0)
		{
			
			found=1;
			s.gpa=0;
			s.total=0;
			float k[5]={4.0,3.0,2.5,1.5,0};
			printf("\n\n\n\t------------UPDATE STUDENT DETAILS----------\n\n");
			printf("\n\n\t ENTER THE NAME          : ");
			scanf("%s",s.name);
			printf("\t ENTER THE INDEX NUMBER  : ");
			scanf("%s",s.index);
			printf("\t ENTER THE DEPARTMENT    : ");
			scanf("%s",s.dep);
			fflush(stdin);
			printf("\tENTER THE COURSE COUNT   : ");
			scanf("%d",&s.c_count);
			for(int i=0;i<s.c_count;i++)
			{
				printf("\t\t\t ENTER COURSE NAME  :  ");
				scanf("%s",s.c[i].c_name);
				fflush(stdin);
				printf("\t\t\t ENTER COURSE GRADE  :  ");
				scanf("%c",&s.c[i].grade);
				if(s.c[i].grade=='a')
				{
					s.c[i].c_value=k[0];
					s.total+=s.c[i].c_value;
				}
				
				else if(s.c[i].grade=='A')
				{
					s.c[i].c_value=k[0];
					s.total+=s.c[i].c_value;
					
				}
				else if(s.c[i].grade=='B')
				{
					s.c[i].c_value=k[1];
					s.total+=s.c[i].c_value;
				}
				else if(s.c[i].grade=='b')
				{
					s.c[i].c_value=k[1];
					s.total+=s.c[i].c_value;
				}
				else if(s.c[i].grade=='C')
				{
					s.c[i].c_value=k[2];
					s.total+=s.c[i].c_value;
				}
				else if(s.c[i].grade=='c')
				{
					s.c[i].c_value=k[2];
					s.total+=s.c[i].c_value;
				}
				else if(s.c[i].grade=='D')
				{
					s.c[i].c_value=k[3];
					s.total+=s.c[i].c_value;
				}
				else if(s.c[i].grade=='d')
				{
					s.c[i].c_value=k[3];
					s.total+=s.c[i].c_value;
				}
				else if(s.c[i].grade=='E')
				{
					s.c[i].c_value=k[4];
					s.total+=s.c[i].c_value;
				}
				else if(s.c[i].grade=='e')
				{
					s.c[i].c_value=k[4];
					s.total+=s.c[i].c_value;
				}
				else{
					s.c[i].c_value=k[4];
					s.total+=s.c[i].c_value;
				}
				
			}
		s.gpa=s.total/(float)s.c_count;
		fwrite(&s,sizeof(struct student),1,temp);
		
		}
	}
	fclose(fp);
	fclose(temp);
	remove("student.txt");
	rename("temp.txt","student.txt");
	printf("\n\n\tRecord updated succsesfully...........");
}

void search()
{
	system("cls");
	FILE *fp;
	struct student s;
	char temp[20];
	int temp1=0;
	fp=fopen("student.txt","r");
	if(fp == NULL)
	{
      printf("Error!");   
      exit(1);             
	}
	printf("\n\t ENETR THE INDEX NUMBER   :   ");
	scanf("%s",temp);
	
	while(fread(&s,sizeof(struct student),1,fp))
	{
		if(strcmp(temp,s.index)==0)
		{
			temp1=1;
			system("COLOR A");
			printf("\n\t  --------STUDENT DETAILS----------");
			printf("\n\n\t STUDENT NAME :-  %s",s.name);
			printf("\n\t DEPARTMENT   :-  %s",s.dep);
			printf("\n\t INDEX NUMBER :-  %s",s.index);
			printf("\n\n\t  ----------COURSE DETAILS-----------");
			for(int i=0;i<s.c_count;i++)
			{
				printf("\n\t COURSE  NAME  :-  %s",s.c[i].c_name);
				printf("\n\t COURSE  GRADE :-  %c",s.c[i].grade);
				printf("\n\t CREDIT VALUE  :-  %.2f\n",s.c[i].c_value);
			}
			printf("\n\t GPA OF THE STUDENT :-  %.2f",s.gpa);
			printf("\n\t__________________________________________");
			
		}
		
		
	}
	if(temp1==0)
		printf("\n\n\tRecord not found   .  .   .  .");
	
	fclose(fp);
}


