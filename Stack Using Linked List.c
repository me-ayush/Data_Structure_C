#include<stdio.h>
#include<stdlib.h>

int m,top=-1;

struct linked_list{
	int data;
	struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL;

void push(int x)
{
	system("cls");
	if(top>=m-1)
	{
		printf("Stack Overflow\n");
		getch();
	}
	else
	{
		node *ptr;
		ptr=(node *)malloc(sizeof(node));
		ptr->data=x;
		if(head==NULL)
		{
			ptr->next=NULL;
		}
		else
		{
			ptr->next=head;
		}
		head=ptr;
		top++;
	}
}

void pop()
{
	system("cls");
	if(top<=-1)
	{
		printf("Stack Underflow\n");
		getch();
	}
	else
	{
		node *temp=head;
		head=head->next;
		printf("Element Poped : %d\n",temp->data);
		getch();
		free(temp);
		top--;
	}
}

void display()
{
	if(top==-1)
		printf("Empty\n");
	else
	{
		node *ptr=head;
		printf("Stack Is : ");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
		getch();
	}
}

int main()
{
	system("cls");
	int ch,x,y;
	printf("Enter Size Of Stack : ");
	scanf("%d",&m);
	printf("\n");
	while(1)
	{
		system("cls");
		printf("[1] For Push\n");
		printf("[2] For Pop\n");
		printf("[3] For Print Stack\n");
		printf("[4] Exit\n\n");
		printf("Your Choice : ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:{
				printf("Element To Be Push : ");
				scanf("%d",&x);
				printf("\n");
				push(x);
				display();
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				exit(0);
				break;
			}
		}
	}
	return 0;
}
