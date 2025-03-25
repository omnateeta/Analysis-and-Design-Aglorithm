//Design and implement c/c++ Program to solve 0/1 knapsac problem using Dynamic Programming method.progra, number-6
#include<stdio.h>
void knapsac(int m,int n,int w[],int p[], int v[][10])
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
				v[i][j]=0;
			else if(j<w[i])
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
	}
}
int max(int i,int j)
{
	if(i>j)
		return i;
	else
		return j;
}

void optimal(int m, int n, int w[],int v[][10])
{
	int i=n,j=m,item=0;
	int x[10];
	while(i!=0&&j!=0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		i=i-1;
	}
	printf("\nOptimal Solution is %d:",v[n][m]);
	printf("\nSelection item are:");
	for(i=1;i<=n;i++)
	{
		if(x[i]==1)
		printf("%4d",i);
	}
}

int main()
{
	int v[10][10],w[10],p[10];
	int i,j,n,m;
	printf("\n*****DYNAMIC KNAPSACK PROBLEM*****\n");
	printf("\nEnter the number of items:");
	scanf("%d",&n);
	printf("\nEnter the weight of each item:\n");
	for(i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	printf("\nEnter the profit of each item:");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("\nEnter the knapsac capacity:");
	scanf("%d",&m);
	knapsac(m,n,w,p,v);
	printf("\nThe content of knapsac table are\n");
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
		printf("%4d",v[i][j]);
		printf("\n");
	}
	optimal(m,n,w,v);
	return 0;
}
