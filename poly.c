#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct poly {
	int expo,coef;
	struct poly *next;
};
struct poly *head=NULL;
struct poly *create()
{
	head=NULL;
	int c;
	do{
	struct poly *newnode,*temp;
	newnode=(struct poly *)malloc(sizeof(struct poly));
	newnode->next=NULL; 
	printf("Enter the exponent and coefficient : ");
	scanf("%d %d",&newnode->expo,&newnode->coef);
	if(head == NULL)
	{
		temp=head=newnode;
		newnode->next=head;
	}
	else{
		temp->next=newnode;
		newnode->next=head;
		temp=newnode;
	}
	printf("enter 1 to add next list else enter 0\n");
	printf("enter choice : ");
	scanf("%d",&c);
	}while(c!=0);
	return head;
}

void display(struct poly* h)
{
	if(h==NULL)
	{
		printf("list is empty\n");
	}
	else{
		struct poly *temp=h;
		printf("polynomial is : \n");
		while(temp->next!=h)
		{
			printf("%d x^%d + ",temp->coef,temp->expo);
			temp=temp->next;
		}
		printf("%d x^%d\n",temp->coef,temp->expo);
	}
}

void evaluate(struct poly* h,int x)
{
	if(h == NULL)
	{
		printf("list is empty\n");
	}
	else{
		int s=0;
		struct poly *temp=h;
		while(temp->next!=h)
		{
			s+=((temp->coef)*(pow(x,temp->expo)));
			temp=temp->next;
		}
		s+=((temp->coef)*(pow(x,temp->expo)));
		printf("Sum of the polynomial is : %d\n",s);
	}
}

void polysum(int x1,int x2)
{
	int s=0;
	struct poly *head1=NULL,*head2=NULL;
	printf("enter the 1st Polynomial : \n");
	head1=create();
	printf("enter the 2nd Polynomial : \n");
	head2=create();
	struct poly *temp1=head1;
	struct poly *temp2=head2;
	printf("Sum of the two polynomials is : \n");
	
	while(temp1->next!=head1 && temp2->next!=head2)
	{
		if(temp1->expo>temp2->expo)
		{
			printf("%d x^%d + ",temp1->coef,temp1->expo);
			s+=((temp1->coef)*(pow(x1,temp1->expo)));
			temp1=temp1->next;
		}
		else if(temp1->expo<temp2->expo)
		{
			printf("%d x^%d + ",temp2->coef,temp2->expo);
			s+=((temp2->coef)*(pow(x2,temp2->expo)));
			temp2=temp2->next;
		}
		else{
			printf("%d x^%d + ",(temp1->coef+temp2->coef),temp1->expo);
			s+=((temp2->coef)*(pow(x2,temp2->expo)))+((temp1->coef)*(pow(x1,temp1->expo)));
			temp1=temp1->next;
			temp2=temp2->next;

		}
	}
	if(temp1->next==head || temp2->next==head)
	{
		if(temp1->expo>temp2->expo)
		{
			printf("%d x^%d + %d x^%d + ",temp1->coef,temp1->expo,temp2->coef,temp2->expo);
			s+=((temp1->coef)*(pow(x1,temp1->expo)))+((temp2->coef)*(pow(x2,temp2->expo)));
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->expo<temp2->expo)
		{
			printf("%d x^%d + %d x^%d + ",temp2->coef,temp2->expo,temp1->coef,temp1->expo);
			s+=((temp2->coef)*(pow(x2,temp2->expo)))+((temp1->coef)*(pow(x1,temp1->expo)));
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else{
			printf("%d x^%d + ",(temp1->coef+temp2->coef),temp1->expo);
			s+=((temp2->coef)*(pow(x2,temp2->expo)))+((temp1->coef)*(pow(x1,temp1->expo)));
			temp1=temp1->next;
			temp2=temp2->next;

		}
	}
	while(temp1!=head1)
	{
		printf("%d x^%d + ",temp1->coef,temp1->expo);
		s=s+((temp1->coef)*(pow(x1,temp1->expo)));
		temp1=temp1->next;
	}
	while(temp2!=head2)
	{
		printf("%d x^%d + ",temp2->coef,temp2->expo);
		s=s+((temp2->coef)*(pow(x2,temp2->expo)));
		temp2=temp2->next;
	}
	printf("\n");
	printf("Sum in terms of value of the two polynomials is : %d\n",s);
}

int main()
{
	struct poly *head3=NULL;
	int x1,x2;
	int ch;
	do{
		printf("Polynomial Operations are : \n");
		printf("1.create\n2.display\n3.evaluate\n4.two polynomial sum\n5.exit\n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:head3=create();
			break;
			case 2:display(head3);
			break;
			case 3:printf("enter the value of x : ");
			scanf("%d",&x1);
			evaluate(head3,x1);
			break;
			case 4:printf("enter the value of x in two polynomials : ");
			scanf("%d %d",&x1,&x2);
			polysum(x1,x2);
			break;
			case 5:printf("..exitting..\n");
			ch=0;
			break;

			default :printf("invalid choice\n");
		}
	}while(ch!=0);
	return 0;
}