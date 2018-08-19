#include <stdio.h>

int n, adj_graph[4][4], visited[10]; 

void dfs(int i)
{
    int j;
    printf("\n%d", i+1);
    visited[i]=1;
    
    for(j=0; j<n; j++)
       if(!visited[j] && adj_graph[i][j]==1)
            dfs(j);
} 

void main()
{
    int i,j;
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
 
    dfs(0);
}
 
