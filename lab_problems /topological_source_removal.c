#include <stdio.h>
#include <stdbool.h>
typedef enum { NO, YES } BOOL;

//int tricky_stack[10], cur = 0;

void source_remove(int n, int adj_graph[4][4])
{
    int i, j;
    int remaining = n;
    do {

        for (j = 0; j < n; ++j) {
            BOOL noic = YES;
            for (i = 0; i < n; ++i)
                if (adj_graph[i][j])
                    noic = NO;
            if (noic) {
                printf("%d\n", j+1);
                for (int k = 0; k < n; ++k) 
                { 
                    adj_graph[j][k] = 0; 
                }
            }
        }

    } while (remaining > 0);


    /*int x = n;
    do
    {
        for (int i = 0; i < n; ++i)
        {
            bool incoming = 1;
            for (int j = 0; j < n; ++j)
            {
                if(adj_graph[j][i]) incoming = 1;
            }
            if(incoming == 0)
                printf("%d\n", i);

            for (int k = 0; k < n; ++k) { adj_graph[i][k] = 0; }
        }

    }while(x > 0)*/
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

    source_remove(n, adj_graph);
    

}
 
