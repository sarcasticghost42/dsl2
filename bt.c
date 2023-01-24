#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *l;
	struct node *r;
}Node;

Node * create(Node *root,int x)
{
	if(x==-1)
	{
		return NULL;
	}
	root = (Node *)malloc(sizeof(Node));
	root->l=NULL;
	root->r=NULL;
	root->data=x;
	printf("enter the data to insert in left sub tree of %d or enter -1 \n",x);
	int d;
	scanf("%d",&d);
	root->l=create(root,d);
	printf("enter the data to insert in right sub tree of %d or enter -1 \n",x);
	int c;
	scanf("%d",&c);
	root->r=create(root,c);
	return root;
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		preorder(root->l);
		preorder(root->r);
	}
	
}

void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		printf("%d\t",root->data);
		inorder(root->r);
	}
	
}

void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->l);
		postorder(root->r);
		printf("%d\t",root->data);
	}
	
}

int search(Node *root,int key,int f)
{
	if(root==NULL)
	return;
	if(root->data==key)
	{
		f=1;
		return f;
	}
	search(root->l,key,f);
	search(root->r,key,f);
}


int main()
{
	int ch,x,key,flag=-1;
	Node *root=NULL;
	do{
		printf("Operations are : \n");
		printf("1.create\n2.preorder\n3.inorder\n4.postorder\n5.search\n6.exit\n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("enter the data :");
			scanf("%d",&x);
			root=create(root,x);
			break;
			case 2:preorder(root);
			printf("\n");
			break;
			case 3:inorder(root);
			printf("\n");
			break;
			case 4:postorder(root);
			printf("\n");
			break;
			case 5:
			printf("enter the number to be searched : ");
			scanf("%d",&key);
			flag=search(root,key,flag);
			if(flag==-1)
			{
				printf("entered element is not present\n");
			}
			else{
				printf("entered element is present \n");
			}
			break;
			case 6:printf("..exitting..\n");
			ch=0;
			break;

			default:printf("Invalid choice\n");

		}
	}while(ch!=0);
	return 0;
}