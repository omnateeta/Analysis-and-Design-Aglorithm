Design and implement c/c++ program to find minimum cost spanning tree of a given connected graph using primns algorithm.
#include<stdio.h>
#include<stdlib.h>

int prims(int cost[][10], int n, int mincost)
{
    int i, j, k, u = 0, v = 0, rearv[10], nearv[10], t[10][3];

    for(i = 2; i < n; i++)
        rearv[i] = 1;

    for(i = 0; i < n; i++)
        nearv[i] = 0;

    for(i = 1; i <= n; i++)
    {
        int min = 999;

        for(j = 0; j < n; j++)
        {
            if(nearv[j] != -1 && cost[j][nearv[j]] < min)
            {
                min = cost[j][nearv[j]];
                v = j;
                u = nearv[j];
            }
        }

        t[i][1] = u;
        t[i][2] = v;
        mincost += cost[v][u];
        nearv[v] = -1;

        for(k = 0; k < n; k++)
        {
            if(nearv[k] != -1 && cost[k][nearv[k]] > cost[k][v])
                nearv[k] = v;
        }

        printf("\n %d minimum edge %d :", i, t[i][1]);
        printf("%d and its cost is %d", t[i][2], min);
    }

    return mincost;
}

int main()
{
    int cost[10][10];
    int n, i, j, mincost = 0;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    mincost = prims(cost, n, mincost);
    printf("\nMinimum spanning tree total cost is %d\n", mincost);
    
    return 0;
}



