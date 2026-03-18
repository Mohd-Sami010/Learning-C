#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10

// --- Adjacency Matrix ---

void init_matrix(int mat[][MAX_V], int v)
{
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            mat[i][j] = 0;
}

void add_edge_mat(int mat[][MAX_V], int u, int v)
{
    mat[u][v] = 1;
    mat[v][u] = 1;
}

void print_matrix(int mat[][MAX_V], int v)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// --- Adjacency List ---

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int v;
    Node **adj;
} Graph;

Node *create_node(int v)
{
    Node *node = malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

Graph *create_graph(int v)
{
    Graph *g = malloc(sizeof(Graph));
    g->v = v;
    g->adj = calloc(v, sizeof(Node *)); // calloc initializes to NULL automatically
    return g;
}

void add_edge_list(Graph *g, int u, int v)
{
    Node *node = create_node(v);
    node->next = g->adj[u];
    g->adj[u] = node;

    node = create_node(u);
    node->next = g->adj[v];
    g->adj[v] = node;
}

void print_list(Graph *g)
{
    printf("\nAdjacency List:\n");
    for (int i = 0; i < g->v; i++)
    {
        Node *temp = g->adj[i];
        printf("%d:", i);
        while (temp)
        {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void free_graph(Graph *g)
{
    for (int i = 0; i < g->v; i++)
    {
        Node *curr = g->adj[i];
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
}

int main()
{
    int v = 4;

    // Graph structure: 0-1, 0-2, 1-2, 2-3

    // Matrix
    int mat[MAX_V][MAX_V];
    init_matrix(mat, v);
    add_edge_mat(mat, 0, 1);
    add_edge_mat(mat, 0, 2);
    add_edge_mat(mat, 1, 2);
    add_edge_mat(mat, 2, 3);

    print_matrix(mat, v);

    // List
    Graph *g = create_graph(v);
    add_edge_list(g, 0, 1);
    add_edge_list(g, 0, 2);
    add_edge_list(g, 1, 2);
    add_edge_list(g, 2, 3);

    print_list(g);
    free_graph(g);

    return 0;
}