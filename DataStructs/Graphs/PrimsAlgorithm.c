#include <stdio.h>
#define MAX_SIZE 100
int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE], parent[MAX_SIZE], key[MAX_SIZE];

void Prims(int n, int start) {
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        key[i] = 9999;
    }

    key[start] = 0;
    for(int i = 0; i < n; i++) {
        int min = 9999, u;
        for(int j = 0; j < n; j++) {
            if(visited[j] == 0 && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        visited[u] = 1;
        for(int v = 0; v < n; v++) {
            if(graph[u][v] != 0 && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int minCost = 0;
    for(int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d-%d %d\n", parent[i], i, key[i]);
            minCost += key[i];
        }
    }
    printf("Minimum cost: %d\n", minCost);
}

int main() {
    int n, e, start;
    scanf("%d", &n);
    scanf("%d", &e);

    for(int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    scanf("%d", &start);

    Prims(n, start);
    return 0;
}