#include<stdio.h>
int main()
{
	int n,min,temp,i,j,c=0,s=0;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			min=j;
			c++;
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
		s++;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n%d\n%d",c,s);
	return 0;
}