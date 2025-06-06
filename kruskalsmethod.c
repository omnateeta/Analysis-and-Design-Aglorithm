#include <stdio.h>
#include <stdlib.h>

int kruskals(int n, int mincost, int cost[][10]) {
    int ne = 1, a = 0, b = 0, u = 0, v = 0, min;
    int parent[10], i, j;

    for (i = 1; i <= n; i++)
        parent[i] = 0;

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u] > 0)
            u = parent[u];
        while (parent[v] > 0)
            v = parent[v];

        if (u != v) {
            printf("\n%d minimum edge is", ne);
            printf(" %d , %2d and its cost is %2d", a, b, min);
            mincost += min;
            parent[v] = u;
            ne++; // only this increment is needed
        }

        cost[a][b] = cost[b][a] = 999;
    }

    return mincost;
}

void main() {
    int cost[10][10];
    int i, j, mincost = 0;
    int n;

    printf("\nKruskals Algorithm\n");
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    mincost = kruskals(n, mincost, cost);
    printf("\nThe minimum spanning tree cost is %2d\n", mincost);
}

