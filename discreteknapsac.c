//Lab-7, Design and implement c/c++ program to solve discrete knapsac and continuous knapsac program using fready approximation method.
#include<stdio.h>
int main()
{
	float weight[50],profit[50],ratio[50],Totalvalue,temp,capacity,amount;
	float x[10];
	int n,i,j;
	printf("\nEnter the number of items:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the weight & profit for the item[%d]:\n",i);
		scanf("%f%f",&weight[i],&profit[i]);
	}
	printf("\nEnter the capacity of the knapsac:");
	scanf("%f",&capacity);
		for(i=0;i<n;i++)
			x[i]=0;
		for(i=0;i<n;i++)
			ratio[i]=profit[i]/weight[i];
		for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
			
				temp=weight[j];
					weight[j]=ratio[i];
				weight[i]=temp;
			
				temp=profit[j];
					profit[i]=temp;
			}
		printf("\nknapsac algorithm using gready algorithm:\n");
		
		for(i=0;i<i<n;i++)
		{
			if(weight[i]>capacity)
				break;
			else
			{
				x[i]=1;
				Totalvalue=Totalvalue+profit[i];
				capacity=capacity-weight[i];
			}
		}
		if(i<n)
		{
			Totalvalue=Totalvalue+(capacity/weight[i])*profit[i];
			x[i]=capacity/weight[i];
		}
		printf("\nX array is as fallows\n");
			for(i=0;i<n;i++)
			printf("\t%2f",x[i]);
			
		printf("\n The maximum value is %f \n",Totalvalue);
		return 0;
}
