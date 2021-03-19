#include<stdio.h>
#include<string.h>
#define MaxSize 50
#define INF 10000000

double graph[MaxSize][MaxSize];
double prim(int n)                 //Initially select vertex 0
{
    double lowcost[n],sum = 0;      //Array lowcost is used to store the shortest distance from the vertex in V-T to T, lowcost[i] = 0 means that vertex i is in tree T
    int count = 1,vetrix[n];        //vetrix[i] means that the distance from i to the vertex vetrix[i] in T is the smallest, used to print the path
    lowcost[0] = 0;
    for(int i = 1;i < n;i++)
    {
        lowcost[i] = graph[0][i];
        vetrix[i] = 0;
    }
    while(count < n)
    {
        double min = INF;
        int min_index;
        for(int i = 1;i < n;i++)
        {
            if(lowcost[i] != 0 && lowcost[i] < min) //Find the edge with the smallest weight <vetrix[i],i>, where vetrix[i] is in T and i is in V-T
            {
    	        min = lowcost[i];       //min records the smallest weight
    	        min_index = i;          //min_index records the vertex corresponding to the smallest edge, that is, the vertex to be added to T
            }
        }
        sum += min;
        lowcost[min_index] = 0;
        count++;
        printf("%d->%d\n", vetrix[min_index],min_index);
        for(int i = 1;i < n;i++)
        {
	    if(lowcost[i] != 0 && lowcost[i] > graph[min_index][i])       //Due to the newly added min_index of the vertex of T, update the shortest distance from the vertex in V-T to T and the corresponding vertex
	        lowcost[i] = graph[min_index][i];
	        vetrix[i] = min_index;      
        }
    }
    return sum;
}

int main()
{
    int n, m, v1, v2;
    double w;
    printf("NAME : AIMAN AL-SUBARI \nID: 20193290730\n");
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            graph[i][j] = INF;
        }
    }
    for(int i = 0;i < m;i++)
    {
        scanf("%d %d %lf",&v1, &v2, &w);
        graph[v1][v2] = graph[v2][v1] = w;
    }
    printf("%lf\n",prim(n));
    return 0;
}
