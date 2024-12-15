#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100

typedef struct Graph {
    int vertices;
    bool isDirected;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices, bool isDirected) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->isDirected = isDirected;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 1;
    }
}

void displayGraph(Graph* graph) {
    printf("Ma tran ke:
");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFSUtil(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS bat dau tu dinh %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

void BFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = 0;
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS bat dau tu dinh %d: ", startVertex);
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, choice, src, dest, startVertex;
    bool isDirected;

    printf("Nhap so dinh: ");
    scanf("%d", &vertices);
    printf("Do thi co huong? (1 la Co, 0 la Khong): ");
    scanf("%d", &isDirected);

    Graph* graph = createGraph(vertices, isDirected);

    do {
        printf("\nMenu:\n");
        printf("1. Them canh\n");
        printf("2. Hien thi do thi\n");
        printf("3. Thuc hien DFS\n");
        printf("4. Thuc hien BFS\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap dinh nguon va dinh dich: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                displayGraph(graph);
                break;
            case 3:
                printf("Nhap dinh bat dau cho DFS: ");
                scanf("%d", &startVertex);
                DFS(graph, startVertex);
                break;
            case 4:
                printf("Nhap dinh bat dau cho BFS: ");
                scanf("%d", &startVertex);
                BFS(graph, startVertex);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 5);

    free(graph);
    return 0;
}

