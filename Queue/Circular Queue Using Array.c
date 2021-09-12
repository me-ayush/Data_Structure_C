#include <stdio.h>
#include<stdlib.h>

int m,*qu,front = -1, last = -1;

int insert(int x)
{
    if((front==0&&last==m-1)||(front==last+1))
    {
        return -1;
    }
    else if(last==-1&&front==-1)
    {
        last=0;
        front=0;
    }
    else if(last==m-1&&front>0)
    {
        last=0;
    }
    else
    {
        last++;
    }
    qu[last]=x;
    return 0;
}

int del() 
{
    if (front==-1) 
    {
          return -1;
    } 
    else if(front==last)
    {
          front=last=-1;
        return -1;
    }
    else
    {
        front++;
    }
    return 0;
}

int display() 
{
	system("cls");
    int i;
    if(front==-1)
    {
        printf("\nQueue Is Empty");
        getch();
		return -1;
    }
	printf("\nQueue Is : ");
   	if(front>last)
    {
        for(i=front;i<m;i++)
        printf("%d ",qu[i]);
        for(i=0;i<=last;i++)
        printf("%d ",qu[i]);
    }
    else
    {
        for(i=front;i<=last;i++)
        printf("%d ",qu[i]);
    }
    printf("\n\nPress Any Key To Conitnue...");
    getch();
    return 0;
}

int main() 
{
	system("cls");
    int ch,q,y;
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
	                printf("\nOverflow");
	                getch();
				}
                else
    	            display();
                break;
            }
            case 2:{
            	system("cls");
                y=del();
                if(y==0)
	                display();
                else
                {
    	            printf("\nUnderflow");
    	            getch();
				}
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
