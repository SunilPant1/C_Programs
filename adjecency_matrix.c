//Implementing Warshall's Algorithm for Calculating Path Matrix
#include<stdio.h>

void warshall(int [][4],int [][4]);
int main(){
    
    int adj[4][4],path[4][4];
    int i,j;
    int n=4;

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("Is there a path from V[%d] to v[%d] (Yes-1/No-0) ? ",i+1,j+1);
            scanf("%d",&adj[i][j]);
        } 
    }

    warshall(adj,path);

    printf("Following are the path matrix \n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d \t",path[i][j]);
        }
        printf("\n");
    }
    
    
    
    return 0;
}

void warshall(int adj[][4],int path[][4]){
    int i,j,k,n=4;

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            path[i][j] = adj[i][j];
        }
    }

    for ( k = 0; k < n; k++)
    {
        for ( i = 0; i < n; i++)
        {
            for ( j= 0; j < n; j++)
            {
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }
}
