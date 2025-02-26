/*Design and implement c/ c++ program to sort a given set of n integer elements using selection sort method and compute its time complexity run the 
progrm for varried values of n > 5000 and record the time taken to sort. plot a graph of the time taken versus n. The elements can be read from a 
file or can be generated using the random number generator */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionsort(int arr[],int n)
{
	int i,j,min=1,temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}		
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] =temp;
	}
}

int main()
{
	int n,i,*arr;
	clock_t start,end;
	double time_taken;
	
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	
	arr =(int*)malloc(n*sizeof(int));
	srand(time(NULL));
	printf("\nElements before sorted\n\n");
	for(i=0;i<n-1;i++)
	{
		arr[i] = rand()%10000;
		printf("\t%d",arr[i]);
	}
	start = clock();
	selectionsort(arr,n);
	end=clock();
	
	time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n sorted array:\n\n");
	
	for(i=0;i<n-1;i++)
	{
		printf("\t %d",arr[i]);
	}
	printf("\n");
	printf("\n Time taken for sorting %d elements is %lf sec \n",n,time_taken);
	
	return 0;
}
