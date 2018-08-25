#include <stdio.h>

//int n, adj_graph[4][4], visited[10]; 
int tricky_stack[10], cur = 0;

void dfs(int i, int n, int adj_graph[4][4], int visited[n])
{
    int j;
    //printf("\n%d", i+1);
    tricky_stack[cur++] = i+1;

    visited[i]=1;
    
    for(j=0; j<n; j++)
       if(!visited[j] && adj_graph[i][j]==1)
            dfs(j, n, adj_graph, visited);
} 

void main()
{
    int i,j;
    int n, adj_graph[4][4], visited[10]; 
    printf("Enter number of vertices:\n");  
    scanf("%d",&n);
    
    printf("\nEnter adjecency matrix: \n");
   
    for(i=0; i<n; i++)
    {
    	for(j=0; j<n; j++)
    	{
    		scanf("%d", &adj_graph[i][j]);
    	}
    }   
  
    for(i=0; i<n; i++)
        visited[i]=0;
 
    dfs(0, n, adj_graph, visited);
    for (int i = cur-1; i >= 0; i--)
    {
        printf("%d\n", tricky_stack[i]);
    }
    printf("\n");
}
 
