#include<stdio.h>
#include<stdlib.h>

int m,*qu,front=-1,last=-1;

int insert(int x)
{
    if(last==m-1)
    {
        return -1;
    }
    else
    {
        if(front==-1)
        {    
            front=0;
        }
        last++;
        qu[last]=x;
    }
    return 0;
}

int del()
{
    if(front==-1)
    {
        return -1;
    }
    else
    {
        front++;
        if(front>last)
        {
            front=last=-1;
            return -1;
        }
    }
    return 0;
}

void display()
{
	system("cls");
    int i;
    if(last==-1)
    {
        printf("\nQueue Is Empty");
    }
    else
    {
    	printf("\nQueue Is : ");
        for(i=front;i<=last;i++)
        {
            printf("%d ",qu[i]);
        }
        printf("\n");
    }
    printf("\n\nPress Any Key To Continue...");
    getch();
}

int main()
{
    int ch,y;
    system("cls");
    printf("\nEnter Size Of Queue : ");
    scanf("%d",&m);
    qu=(int*)malloc(sizeof(int)*m);
    while(1)
    {
    	system("cls");
    	printf("\n[1] For Insert");
    	printf("\n[2] For Delete");
    	printf("\n[3] For Print Queue");
    	printf("\n[4] Exit");
    	printf("\n\nYour Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:{
            	system("cls");
                int x;
                printf("\nElement To Be Insert : ");
                scanf("%d",&x);
                y=insert(x);
                if(y==-1)
                {
	                printf("\n\nOverflow...");
					getch();
				}
                else
    	            display();
                break;
            }
            case 2:{
            	system("cls");
                y=del();
                if(y==-1)
                {
	                printf("\nUnderflow...");
					getch();
				}
                else
	                display();
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
}
