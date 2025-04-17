//Design and implement c program to solve all-pairs shortest paths problem using Floyd's algorithm.
#include<stdio.h>
void floyd(int a[][10],int n)
{
	int k;
	for(k=1;k<=n;k++)
	{
		int i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	}
}
int min(int a, int b)
{
	if(a>b)
		return b;
	else
		return a;
}

void main()
{
	int a[10][10];
	int i,j,n;
	printf("\n\tFloyds Alogorithm\n");
	printf("\nEnter the number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adecency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
		floyd(a,n);
		
	printf("\nAll pair shortest path matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		 printf("%d\t",a[i][j]);
		 printf("\n");
	}
	printf("\n********\n");
}
