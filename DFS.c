#include <stdio.h>
#include <stdlib.h>

int arr[20][20];
int visited[20];

void dfs(int start, int n) {
    visited[start] = 1;
    for(int i = 0; i < n; i++) {
        if(arr[start][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int isConnected(int n) {
    dfs(0, n);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edges:\n");
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    if(isConnected(n)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
