#include <stdio.h>
#define MAX_SIZE 100
int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE], parent[MAX_SIZE], distance[MAX_SIZE];

void Prims(int n, int start) {
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        distance[i] = 9999;
    }

    distance[start] = 0;
    for(int i = 0; i < n; i++) {
        int minIndex = -1;
        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && (minIndex == -1 || distance[j] < distance[minIndex])) {
                minIndex = j;
            }
        }
        visited[minIndex] = 1;

        for(int j = 0; j < n; j++) {
            if(graph[minIndex][j] && !visited[j] && graph[minIndex][j] < distance[j]) {
                parent[j] = minIndex;
                distance[j] = graph[minIndex][j];
            }
        }
    }

    int minCost = 0;
    for(int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d-%d %d\n", parent[i], i, distance[i]);
            minCost += distance[i];
        }
    }
    printf("Minimum cost: %d\n", minCost);
}

int main() {
    int n, e, start;
    scanf("%d", &n);
    scanf("%d", &e);
    n++;
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