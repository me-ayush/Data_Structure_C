#include<stdio.h>
#include<stdlib.h>

int *a,top=-1,m;
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
		top=top+1;
		a[top]=x;
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
		printf("\nElement Poped : %d",*(a+top));
		getch();
		top--;
	}
}
void display()
{
	system("cls");
	if(top>=0)
	{
		int i;
		printf("\nStack Is : ");
		for(i=top;i>=0;i--)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		getch();
	}
	else
	{
		printf("\nStack Is Empty");
		getch();
	}
}

int main()
{
	system("cls");
	int ch,x;
	printf("Enter Size Of Stack : ");
	scanf("%d",&m);
	a=(int *)malloc(sizeof(int)*m);
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
