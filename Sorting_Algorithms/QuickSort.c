/* C implementation QuickSort */
#include<stdio.h> 
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 


int partition(int arr[],int low,int high)
{
   int i, j, pivot, temp;

   if(low<high)
   {
      pivot=low;
      i=low;
      j=high;

      while(i<j)
	  {
         while(arr[i]<=arr[pivot] && i<high)
            i++;
            
         while(arr[j]>arr[pivot])
            j--;
            
         if(i<j)
		 {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
	return j;
}
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 


// Driver program to test above functions 
int main() 
{ 
	int n,i;
	printf("Enter n:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter %d elements:\n",n);
	for(i=0;i<n;i++)
	   scanf("%d",&arr[i]); 
	
	quickSort(arr, 0, n-1); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 
