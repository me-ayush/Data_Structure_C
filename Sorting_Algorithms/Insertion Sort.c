#include<stdio.h>

int main()
{
	int i,j,n,k,c=0;
	printf("Enter The Size Of Elements : ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter The [%d] Element : ",i+1);
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		k=a[i];
		j=i-1;
		while(j>=0&&a[j]>k)
		{
			a[j+1]=a[j];
			c++;
			j--;
		}
		a[j+1]=k;
	}
	printf("\nSorted Array Is : \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
		
	printf("\n\nNumber Of : %d\nNumber Of Comparison : %d",((n*n)-n)/2,c);
}
