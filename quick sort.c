/*Design and implement c/c++ program to sort a given set of n integerelements using Quick Sort method and compute iys time complexity. 
Run the program for varied values of n>5000 and record the time takn to sort plot a graph of the time taken versus n. The elements can be read from a file
or can be generated using the random number.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int low, int high)
{
	int pivot = arr[low];
	int i=low;
	int j=high;
	while(i<j)
	{
		int pivot = arr[low];
		int i=low;
		int j=high;
		while(i<j)
		{
			do{
				i=i+1;
			}while(arr[i]<=pivot);
			if(i<j)
			{
				swap(&arr[i],&arr[j]);
			}
		}
		swap(&arr[low], &arr[j]);
		return j;
	}
}
void quicksort(int arr[],int low,int high)
{
	int partitionIdex;
	if(low<high){
		partitionIdex=partition(arr,low,high);
		quicksort(arr,low,partitionIdex-1);
		quicksort(arr, partitionIdex+1,high);
	}
}

int main()
{
	clock_t start,end;
	double time_taken;
	int i,n,*arr;
	
	printf("\nEnter the number of the elements:");
	scanf("%d",&n);
	
	arr=(int*)malloc(n*sizeof(int));
	srand(time(NULL));
	
	printf("\n\nElements before sorting:\n");
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%10000;
		printf("%5d",arr[i]);
	}
	start=clock();
	quicksort(arr,0,n-1);
	end=clock();
	
	time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("\n\nSorted array:\n");
	for(i=0;i<n;i++)
	{
		printf("%5d",arr[i]);
	}
	printf("\n");
	printf("\n\nThe time_taken to sort %d element is: %1f sec",n,time_taken);
	
	free(arr);
	return 0;
}
