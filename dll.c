#include <stdio.h>
#include <stdlib.h>

struct node{
	char ssn[20],name[20],dep[20],des[20],sal[20],ph[20];
	struct node *next;
	struct node *prev;
};
static int count = 0;
struct node *head=NULL,*tail=NULL;
struct node * info()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	newnode->prev=NULL;
	printf("enter USN : ");
	scanf("%s",newnode->ssn);
	printf("enter name : ");
	scanf("%s",newnode->name);
	printf("enter department : ");
	scanf("%s",newnode->dep);
	printf("enter designation : ");
	scanf("%s",newnode->des);
	printf("enter Salary : ");
	scanf("%s",newnode->sal);
	printf("enter phone number : ");
	scanf("%s",newnode->ph);
	return newnode;
}
void create()
{
	int c;
	do{
		struct node *l;
		printf("enter the data :\n");
		l=info();
		if(head==NULL)
		{
			head=tail=l;
		}
		else{
			l->prev=tail;
			tail->next=l;
			tail=l;
		}
		count++;
		printf("if you want to link a newnode enter 1 or else enter 0\n");
		printf("enter your choice : ");
		scanf("%d",&c);
	}while(c!=0);
}

void display()
{
	if(head == NULL)
	{
		printf("list is empty\n");
	}
	else{
		struct node* temp=head;
		printf("list elements are :\n");
		printf("SSN\tName\tDepartment\tdesignation\tSalary\tphone number\n");
		while(temp!=NULL)
		{
			printf("%s\t%s\t%s\t%s\t%s\t%s\n",temp->ssn,temp->name,temp->dep,temp->des,temp->sal,temp->ph);
			temp=temp->next;
		}
		printf("\n");
		printf("Number of Listnodes are : %d\n",count);
	}
}

void insf()
{
	struct node *newnode;
	printf("enter the data :\n");
	newnode=info();
	if(head==NULL)
	{
		head=tail=newnode;
	}
	else{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
}

void inse()
{
	struct node *newnode;
	printf("enter the data :\n");
	newnode=info();
	if(head==NULL)
	{
		head=tail=newnode;
	}
	else{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
}

void delf()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty \n");
	}
	else{
		temp=head;
		head=head->next;
		head->prev=NULL;
		printf("deleted list is :\n");
		printf("USN : %s\nName : %s\nDepartment : %s\nDesignation : %s\nSalary : %s\nPhone Number : %s\n",temp->ssn,temp->name,temp->dep,temp->des,temp->sal,temp->ph);
	    free(temp);
	}
}

void dele()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty \n");
	}
	else{
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		printf("deleted list is :\n");
		printf("USN : %s\nName : %s\nDepartment : %s\nDesignation : %s\nSalary : %s\nPhone Number : %s\n",temp->ssn,temp->name,temp->dep,temp->des,temp->sal,temp->ph);
		free(temp);
	}
}

int main()
{
	int ch;
	do{
		printf("Operations are :\n");
		printf("1.create\n2.display\n3.insert at beginning\n4.insert at end\n5.delete from beginning\n6.delete from end\n7.exit\n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
			break;
			case 2:display();
			break;
			case 3:insf();
			break;
			case 4:inse();
			break;
			case 5:delf();
			break;
			case 6:dele();
			break;
			case 7:printf("..Exitting..");
			exit(0);

			default:printf("Invalid choice \n");
		}
	}while(1);
	return 0;
}