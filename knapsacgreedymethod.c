#include<stdio.h>
int main()
{
	float weight[50], profit[50], ratio[50], Totalvalue = 0, temp, capacity, amount;
	float x[50] = {0};  // Increased size to match weight[] & initialized
	int n, i, j;
	
	printf("\nEnter the number of items:");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		printf("\nEnter the weight and profit of item [%d]:\n", i);
		scanf("%f %f", &weight[i], &profit[i]);
	}
	
	printf("\nEnter the capacity of the knapsack: ");
	scanf("%f", &capacity);
	
	for(i = 0; i < n; i++)
		ratio[i] = profit[i] / weight[i];
	
	// Sorting items based on ratio in descending order
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(ratio[i] < ratio[j])
			{
				// Swap ratio
				temp = ratio[i];
				ratio[i] = ratio[j];
				ratio[j] = temp;

				// Swap weight
				temp = weight[i];
				weight[i] = weight[j];
				weight[j] = temp;

				// Swap profit
				temp = profit[i];
				profit[i] = profit[j];
				profit[j] = temp;
			}
		}
	}
	
	printf("\nKnapsack algorithm using greedy approach:\n");
	for(i = 0; i < n; i++)
	{
		if(weight[i] > capacity)
			break;
		else
		{
			x[i] = 1;
			Totalvalue += profit[i];
			capacity -= weight[i];
		}
	}
	if(i < n)
	{
		x[i] = capacity / weight[i];
		Totalvalue += x[i] * profit[i];
	}
	
	printf("\nThe maximum value is %f\n", Totalvalue);
	return 0;
}

