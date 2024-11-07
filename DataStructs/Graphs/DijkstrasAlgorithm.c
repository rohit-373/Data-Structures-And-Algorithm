#include <stdio.h>
#include <limits.h>
#define MAX_SIZE 100
int graph[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE], visited[MAX_SIZE];

void dijkstras(int n, int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int minIndex = -1;
        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && (minIndex == -1 || dist[j] < dist[minIndex])) {
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[minIndex][j] && dist[minIndex] + graph[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int start;
    scanf("%d", &start);
    dijkstras(n, start);
    return 0;
}