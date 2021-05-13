/* Given n points placed such that no 3 of them are colinear, connect all of them with others with coloured edge (red or black).
Find number of same-coloured triangles formed.

Input:
3 <= n <= 1000
0 <= m <= n(n-1)/2
m rows of integer pairs (p, q) representing red edges

Output: 
One integer - sum of all same-coloured triangles

Example:
Input: 
6 9
1 2
2 3
2 5
1 4
1 6
3 4
4 5
5 6
3 6

Output:

2 */

#include <stdio.h>
#include <stdlib.h>

void multiply(int **A, int **B, int **C, int V) //Utility function for matrix multiplication
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < V; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

//Utility function to calculate trace of a matrix (sum of diagnonal elements)
int getTrace(int **graph, int V)
{
    int trace = 0;
    for (int i = 0; i < V; i++)
        trace += graph[i][i];
    return trace;
}

//  Utility function for calculating number of triangles in graph
int triangleInGraph(int **graph, int V)
{
    // To Store graph^2
    int **aux2 = (int **)malloc((unsigned)V * sizeof(int *)); //allocate memory for array
    for (int i = 0; i < V; i++)
        aux2[i] = (int *)malloc((unsigned)V * sizeof(int)); //allocate each row

    // To Store graph^3
    int **aux3 = (int **)malloc((unsigned)V * sizeof(int *)); //allocate memory for array
    for (int i = 0; i < V; i++)
        aux3[i] = (int *)malloc((unsigned)V * sizeof(int)); //allocate each row

    //  Initialising aux
    // matrices with 0
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
        {
            aux2[i][j] = 0;
            aux3[i][j] = 0;
        }

    // aux2 is graph^2 now  printMatrix(aux2);
    multiply(graph, graph, aux2, V);

    // after this multiplication aux3 is
    // graph^3 printMatrix(aux3);
    multiply(graph, aux2, aux3, V);

    int trace = getTrace(aux3, V);
    for (int i = 0; i < V; i++) //free memory
    {
        free(aux2[i]);
        free(aux3[i]);
    }
    free(aux2);
    free(aux3);
    return trace / 6;
}

int main()
{
    int n = 0, m = 0, v1 = 0, v2 = 0, result = 0;
    printf("Enter n and m: \n");
    scanf("%d %d", &n, &m);
    int **arr = (int **)malloc((unsigned)n * sizeof(int *)); //allocate memory for adjacency array
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc((unsigned)n * sizeof(int)); //allocate each row
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &v1, &v2); //form adjacency array of red edges
        arr[v1 - 1][v2 - 1] = 1;
        arr[v2 - 1][v1 - 1] = 1;
    }

    result += triangleInGraph(arr, n); //find red triangles
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) //flip all 0 and ones, effectively getting adjacency matrix of black edges (we know that all points are connected)
            if (arr[i][j] == 1)
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
    for (int i = 0; i < n; i++)
        arr[i][i] = 0;                 //remove ones from main diagonal - it's a simple graph!
    result += triangleInGraph(arr, n); //find black triangles
    printf("Number of same-coloured triangles: %d", result);
    for (int i = 0; i < n; i++) //free memory
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}