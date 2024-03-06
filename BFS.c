#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;

void BFS(int start, int n) {
    visited[start] = 1;
    queue[++rear] = start;

    while(front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for(int i = 0; i < n; i++) {
            if(graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edges:\n");
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    BFS(start, n);

    return 0;
}
