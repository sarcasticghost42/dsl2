//sll
#include <stdio.h>
#include <stdlib.h>

struct node{
	char usn[20],name[20],prog[20],sem[20],ph[20];
	struct node *next;
};
static int count = 0;
struct node *head=NULL,*tail=NULL;
struct node * info()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("enter USN : ");
	scanf("%s",newnode->usn);
	printf("enter name : ");
	scanf("%s",newnode->name);
	printf("enter programme : ");
	scanf("%s",newnode->prog);
	printf("enter semester : ");
	scanf("%s",newnode->sem);
	printf("enter phone number : ");
	scanf("%s",newnode->ph);
	return newnode;
}
void create()
{
	int c;
	do{
		struct node *temp,*l;
		printf("enter the data :\n");
		l=info();
		if(head==NULL)
		{
			temp=head=tail=l;
		}
		else{
			head=l;
			head->next=temp;
			temp=head;
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
		printf("USN\tName\tProgramme\tsemester\tphone number\n");
		while(temp!=NULL)
		{
			printf("%s\t%s\t%s\t\t%s\t%s\n",temp->usn,temp->name,temp->prog,temp->sem,temp->ph);
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
		printf("deleted list is :\n");
		printf("USN : %s\nName : %s\nProgramme : %s\nSemester : %s\nPhone Number : %s\n",temp->usn,temp->name,temp->prog,temp->sem,temp->ph);
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
		temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
		tail=temp;
		temp=temp->next;
		printf("deleted list is :\n");
		printf("USN : %s\nName : %s\nProgramme : %s\nSemester : %s\nPhone Number : %s\n",temp->usn,temp->name,temp->prog,temp->sem,temp->ph);
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