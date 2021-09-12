#include <stdio.h>
#include <string.h>
#include<windows.h>
#include <stdlib.h>

struct linked_list
{
    int data;
    struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL;

//Function To Check List Is Empty Or Not
int check_list()
{
	system("cls");
	if(head==NULL)
	{
		printf("\nList Not Created Yet !!!");
    	printf("\n\nPress Any Key To Continue...");
		getch();
		return 0;
	}
	return 1;
}

//Function To Print List
void print_list()
{
	system("cls");
    if(check_list())
    {
	    node *ptr=head;
    	printf("\nList : ");
	    while(ptr!=NULL)
	    {
	        printf("%d ",ptr->data);
	        ptr=ptr->next;
	    }
	    printf("\n");
	    printf("\n\nPress Any Key To Continue...");
		getch();
	}
}

//Function To Add Element At Begning(Pass 0) Or At End(Pass 1)
void insert(int x,int y)
{
	node *ptr,*tmp;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=x;
	if(head==NULL)
	{
		ptr->next=NULL;
		head=ptr;
	}
	else if(y==0)
	{
		ptr->next=head;
		head=ptr;
	}
	else
	{
		tmp=head;
		while(tmp->next!=NULL)
			tmp=tmp->next;
		ptr->next=NULL;
		tmp->next=ptr;
	}
}

//Function To Add Element At Particular Position
int insert_pos(int x,int t)
{
    node *ptr,*tmp;
    tmp=(node *)malloc(sizeof(node));
    ptr=head;
    while(t--)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        tmp->data=x;
        tmp->next=NULL;
        ptr=tmp;
    }
    else
    {
        tmp->data=x;
        tmp->next=ptr->next;
        ptr->next=tmp;
   }
    return 0;
}

//Function To Delete Element At Begning(Pass 0) Or At End(Pass 1)
int del_el(int x)
{
	int z;
	node *ptr,*tmp;
	if(x==0)
	{
		ptr=head;
		z=ptr->data;
		head=head->next;
		free(ptr);
	}
	else
	{
		tmp=ptr=head;
		while(ptr->next!=NULL)
		{
			tmp=ptr;
			ptr=ptr->next;
		}
		tmp->next=NULL;
		z=ptr->data;
		free(ptr);
	}
	return z;
}

//Function To Delete Element
int del(int x)
{
    node *ptr,*tmp;
    ptr=head;
    if(ptr->data==x)
    {
        head=ptr->next;
        free(ptr);
    }
    else
    {
        while((ptr!=NULL)&&(ptr->data!=x))
        {
            tmp=ptr;
            ptr=ptr->next;
        }
        if(ptr!=NULL)
        {
            tmp->next=ptr->next;
            free(ptr);
        }
    }
    return 0;
}

//Funciton To Return Element At x Index
int inde(int x)
{
	node *ptr;
	ptr=head;
	while(x--)
	{
		ptr=ptr->next;
		if(ptr==NULL&&x!=0)
		{
			return -1;
		}
	}
	return ptr->data;
}

//Function To Search Element
int search(int x)
{
    node *ptr;
    ptr=head;
    int c=0;
    while(ptr!=NULL)
    {
        if(ptr->data==x)
        {
            return c;
        }
        ptr=ptr->next;
        c++;
    }
    return -1;
}

//Function To Reverse The List
void reverse_print()
{
    node *temp,*temp1;
    temp=NULL,temp1=NULL;
    while(head!=NULL)
    {
        temp1=head->next;
        head->next=temp;
        temp=head;
        head=temp1;        
    }
    head=temp;
}

int main()
{
    int ch,ch2,x,y,t;
    while(1)
    {
    	system("cls");
    	printf("\n[1] For Insertion");
		printf("\n[2] For Deletion");
		printf("\n[3] For Reverse");
		printf("\n[4] For Searching");
		printf("\n[5] Print List");
		printf("\n[6] Exit");
		printf("\n\nYour Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
				system("cls");
				printf("\nEnter The X : ");
   				scanf("%d",&x);
   				system("cls");
				printf("\n\nWhere You Want To Insert %d : ",x);
				printf("\n\n[1] At Begning");
				printf("\n[2] At End");
				printf("\n[3] For Insertion X After Y If Exist else At End");
				printf("\n[4] For Insertion X Before Y If Exist else At Begning");
				printf("\n\n Your Choice : ");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:{
    			        insert(x,0);
       	 		        print_list();
						break;
					}
					case 2:{
						insert(x,1);
                		print_list();
						break;
					}
					case 3:{
						system("cls");
						printf("\nInsert %d After : ",x);
		        		scanf("%d",&y);
		            	t=search(y);
		            	if(t==-1||head==NULL)
		            	{
		            		insert(x,1);
						}
		            	else
			                insert_pos(x,t);
		                print_list();
						break;
					}
					case 4:{
						system("cls");
						printf("\nInsert %d Before : ",x);
		        		scanf("%d",&y);
		            	t=search(y);
		            	if(t==-1||t==0||head==NULL)
		            		insert(x,0);
		            	else
			                insert_pos(x,t-1);
		                print_list();
						break;
					}
				}
				break;
			}
			case 2:{
				system("cls");
				if(check_list())
				{
					printf("\n\n[1] At Begning");
					printf("\n[2] At End");
					printf("\n[3] At Particular Index");
					printf("\n[4] Particular Element");
					printf("\n\nYour Choice : ");
					scanf("%d",&ch2);
					system("cls");
					switch(ch2)
					{
						case 1 :{
							int z=del_el(0);
							printf("\nDeleted Element : %d",z);
							getch();
							break;
						}
						case 2:{
							int z=del_el(1);
							printf("\nDeleted Element : %d",z);
							getch();
							break;
						}
						case 3:{
							printf("\nAt Index : ");
							scanf("%d",&y);
							system("cls");
							int z=inde(y);
							if(z==-1)
							{
								printf("\nElement Not Exist At %d Index",y);
								getch();
							}
							else
							{
								del(z);
				     		    printf("\nDeleted Item : %d\nAt Index %d",z,y);
				     		    getch();
							}
							break;
						}
						case 4:{
							printf("\nEnter Element To Be Deleted : ");
					        scanf("%d",&x);
				    	    t=search(x);
				        	if(t==-1)
				        	{
				            	printf("\nElement Not Found...");
				            	getch();
							}
				            else
				            {
					            del(x);
				     		    printf("\nDeleted Item : %d\nFound At Index %d",x,t);
				     		    getch();
							}
							break;
						}
					}
				}
				break;
			}
			case 3:{
				system("cls");
				if(check_list())
				{
					reverse_print();
					print_list();
				}
				break;
			}
			case 4:{
				system("cls");
				if(check_list())
				{
					printf("\nEnter Element To Be Search : ");
	        		scanf("%d",&x);
	                t=search(x);
	                if(t==-1)
	                {
	                	printf("\nElement Not Exist In List");
					}
					else
		                printf("\nElement Found At : %d Position",t+1);
	                getch();
				}
				break;
			}
			case 5:{
				print_list();
				break;
			}
			case 6:{
				exit(0);
				break;
			}
		}
    }
}
