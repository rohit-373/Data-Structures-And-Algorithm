#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int parent[MAX];

int find(int i) {
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int n) {
    int mincost = 0; // Cost of min MST.
    for (int i = 0; i < n; i++)
        parent[i] = -1;

    int edge_count = 0;
    while (edge_count < n - 1) {
        int min = 9999, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && graph[i][j] < min && graph[i][j] != 0) {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a == -1 && b == -1) {
            printf("No spanning tree\n");
            return;
        }

        union1(a, b);
        printf("%d-%d %d\n", a, b, min);
        edge_count++;
        mincost += min;
    }
    printf("Minimum cost: %d\n", mincost);
}

int main() {
    int n, m, u, v, w;

    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    kruskal(n);

    return 0;
}