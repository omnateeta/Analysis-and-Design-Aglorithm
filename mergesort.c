#include"stdio.h"
#include"time.h"

void mergesort(int*,int,int);
int merge(int*,int,int,int);
int n;

void mergesort(int a[], int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int merge(int a[], int low, int mid, int high)
{
	int i,j,h,k,*b;
	b=(int*)malloc(n*sizeof(int));
	h=low;
	i=low;
	j=mid+1;
	while((h<=mid)&&(j<=high))
	{
		if(a[h]<a[j]){
			b[i]=a[h];
			h=h+1;
		}else{
			b[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	if(h>mid){
		for(k=j;k<=high;k++){
			b[j]=a[k];
			i=i+1;
		}
	}
	else{
		for(k=h;k<=mid;k++){
			b[i]=a[k];
			i=i+1;
		}
	}
	for(k=low; k<=high;k++)
	 a[k]=b[k];
}

void main()
{
	int *arr,i;
	clock_t start,end;
	double time_taken;
	
	printf("\n**MERGE SORT PROGRAM**\n");
	printf("\nEnter the number of elements to be sorted:\n");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	srand(time(NULL));
	
	printf("\nArray elements before sorting:\n");
	for(i=0;i<n;i++)
	{
		arr[i]=rabd()%10000;
		printf("%5d",arr[i]);
	}
	printf("\mArray elements to be sorted are\n");
	for(i=0;i<n;i++)
		printf("%5d",arr[i]);
		start=clock();
		mergesort(arr,0,n-1);
		end=clock();
		
		time_taken=((double)(end-start))/CLOCKS_PER_SEC;
		printf("\nThe sorted elements are\n");
		for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
			printf("\n\nThe time taken to sort %d elements is %1f sec",n,time_taken);
}
