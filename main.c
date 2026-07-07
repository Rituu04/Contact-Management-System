#include<stdio.h>
#include<conio.h>
#include<string.h>
					
struct list{
	char name[20];
	char phone[30];
	char address[30]; 
	char email[20];
}li,check; 

void CreateContact()      
{
	FILE *fp; 
	fp = fopen("contact.txt","a+");
	
	system("cls");
	printf("\t\t===========================\n\n");
	printf("\t\t        NEW CONTACT        \n\n");
	printf("\t\t=========================== \n");
	
	printf("\t\tInput name :");   
	fflush(stdin);
	gets(li.name);
	
	printf("\t\tInput phone :"); 
	fflush(stdin); 
	gets(li.phone);
	     
	printf("\t\tInput address :"); 
	fflush(stdin); 
	gets(li.address);
	
	printf("\t\tInput email :"); 
	fflush(stdin); 
	gets(li.email);
	
	fprintf(fp,"%s %s %s %s \n",li.name,li.phone,li.address,li.email);
	fclose(fp);
	printf("\t\t=====SUCCESSFUL=====\n\n");
	system("pause");
}
void EditContact()
{                             
	system("cls");
	int ch,f=0;
	FILE *fp,*newrec;
	fp = fopen("contact.txt","r");
	newrec = fopen("temp.txt","w");	
	printf("\t\t===========================\n\n");
	printf("\t\t\t EDIT CONTACT\n\n");
	printf("\t\t===========================\n");
	printf("\t\t Enter name :"); 
	fflush(stdin); 
	gets(check.name);
	
	while(fscanf(fp,"\t\t %s %s %s %s\n",li.name,li.phone,li.address,li.email) != EOF)
	{
		if(strcmp(check.name,li.name) == 0)
		{
			f=1;	
			do
			{
				system("cls");
				printf("\t\t===========================\n\n");
				printf("\t\t\t EDIT CONTACT\n\n");
				printf("\t\t===========================\n");
				printf("\t\t  What you want to edit\n");
				printf("\t\t 1. Name \n");
				printf("\t\t 2. Phone\n");
				printf("\t\t 3. Address \n");
				printf("\t\t 4. Email\n");
				printf("\t\t 0. Back\n");
				printf("\t\t===========================\n");
				printf("\t\t\tEnter option :");
				scanf("%d",&ch);
				
				switch(ch)
				{
					case 1: 
					
						printf("\t\tEnter New name :"); 
						fflush(stdin); 
						gets(li.name);
						printf("\t\t=====SUCCESSFUL=====\n\n");
						system("pause");
						break;
							
					case 2: 
					
						printf("\t\tEnter new phone :"); 
						fflush(stdin); 
						gets(li.phone);
						printf("\t\t=====SUCCESSFUL=====\n\n");
						system("pause");
						break;
						
					case 3: 
					
						printf("\t\tEnter new address :"); 
						fflush(stdin); 
						gets(li.address);
						printf("\t\t=====SUCCESSFUL=====\n\n");
						system("pause");
						break;
					case 4: 
					
						printf("\t\tEnter new email :"); 
						fflush(stdin); 
						gets(li.email);
						printf("\t\t=====SUCCESSFUL=====\n\n");
						system("pause");
						break;
						
					case 0: 
					
						fprintf(newrec,"\t\t %s %s %s %s\n",li.name,li.phone,li.address,li.email);
						break;
				}	
			}while(ch != 0);
		}
		else
		{
			fprintf(newrec,"\t\t %s %s %s %s\n",li.name,li.phone,li.address,li.email);
		}
		
	}
	fclose(fp);
	fclose(newrec);
	remove("contact.txt");
	rename("temp.txt","contact.txt");
	if(f == 0)
	{
		printf("Cannot found the name \n\n");
		system("pause");  
	}
}

void SearchContact()
{
	int f=0;
	FILE *fp;
	fp = fopen("contact.txt","r");
	
	system("cls");
	printf("\t\t===========================\n\n");
	printf("\t\t\t SEARCH CONTACT\n\n");
	printf("\t\t===========================\n");
	printf("\t\t Enter name :");
	fflush(stdin); 
	gets(check.name);
	
	while(fscanf(fp,"\t\t %s %s %s %s\n",li.name,li.phone,li.address,li.email) != EOF)
	{
		if(strcmp(check.name,li.name)==0)
		{
			f=1;
			printf("\t\t Name    : %s\n",li.name);
			printf("\t\t Phone   : %s\n",li.phone);
			printf("\t\t Address : %s\n",li.address);
			printf("\t\t Email   : %s\n",li.email);
			system("pause");
			break;
		}
	}
	fclose(fp);
	if(f == 0)
	{
		printf("Cannot found the name \n\n");
		system("pause");  
	}
			
}


void ListContact()
{
	int f=0;
	FILE *fp;
	fp = fopen("contact.txt","r");
	
	system("cls");
	printf("\t\t===================================================================================================================\n\n");
	printf("\t\t                                                LIST CONTACT                   \n");
	printf("\t\t===================================================================================================================\n\n");
	
	printf("\t\t %-30s%-30s%-40s%-40s\n","NAME","PHONE","ADDRESS","EMAIL");

	while(fscanf(fp,"\t\t %s %s %s %s\n",li.name,li.phone,li.address,li.email)!=EOF)
	{
		printf("\t\t %-30s%-30s%-40s%-40s\n",li.name,li.phone,li.address,li.email);	
	}
	fclose(fp);
	
	if(f == 0)
	{
		printf("This is Record\n\n");
		system("pause");  
	}

}
void DeleteContact()
{
	system("cls");
	int ch,f=0;
	FILE *fp,*newrec;
	fp = fopen("contact.txt","r");
	newrec = fopen("temp.txt","w");	
	printf("\t\t===========================\n\n");
	printf("\t\t\t DELETE CONTACT\n\n");
	printf("\t\t===========================\n");
	printf("\t\t Enter name :");
	fflush(stdin);
	gets(check.name);
	
	while(fscanf(fp,"%s %s %s %s\n",li.name,li.phone,li.address,li.email) != EOF)
	{
		if(strcmp(check.name,li.name) == 0)
		{
			f=1;
		}
		else
		{
			fprintf(newrec,"\t\t %s %s %s %s\n",li.name,li.phone,li.address,li.email);	
		}
	}
	fclose(fp);
	fclose(newrec);
	remove("contact.txt");
	rename("temp.txt","contact.txt");
	if(f == 1)
	{
		printf("\t\t\t=============== SUCCESSFUL=============== \n\n");
		system("pause");  
	}
	else
	{
		printf("\t\t\tCannot found the name \n\n");
		system("pause");	
	}
		
}
void main()
{
	int ch;
	do{
		system("cls");
		printf("\t\t===========================\n\n");
		printf("\t\t\tMAIN MENU\n\n");
		printf("\t\t===========================\n");
		printf("\t\t1. Create new contact\n");
		printf("\t\t2. Edit contact\n");
		printf("\t\t3. Search contact\n");
		printf("\t\t4. List contact\n");
		printf("\t\t5. Delete contact\n");
		printf("\t\t0. Exit\n");
		printf("\t\t===========================\n");
		printf("\t\t\tEnter option :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				
				CreateContact();
				break;
				
			case 2:
				
				EditContact();
				break;
				
			case 3:
				
				SearchContact();
				break;
				
			case 4:
				
				ListContact();
				break;
				
			case 5:
				
				DeleteContact();
				break;

		}
	}while(ch !=0);
}

