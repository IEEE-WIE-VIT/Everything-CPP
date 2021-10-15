/*/*
T = Ø;
U = { 1 };
while (U ? V)
    let (u, v) be the lowest cost edge such that u ? U and v ? V - U;
    T = T ? {(u, v)}
    U = U ? {v}*/


#include <stdio.h>
#include <limits.h>
#include <iostream>
#define V 5//define no of vertices in the graph

using namespace std;


int minKey(int key[], bool set[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    if (set[v] == false && key[v] < min)
    min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int n, int graph[V][V]) {
    cout<<"Weight of Edge:\n";
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[V][V]) {
    int parent[V]; 
    int key[V]; 
    bool set[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, set[i] = false;
    key[0] = 0; 
    parent[0] = -1; 
    for (int count = 0; count < V - 1; count++){
        int u = minKey(key, set);
        set[u] = true;
        for (int v = 0; v < V; v++)  
            if (graph[u][v] && set[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph);
}
int main() {
    int graph[V][V] =  {{0, 9, 75, 0, 0},
                       {9, 0, 95, 19, 42},
                       {75, 95, 0, 51, 66},
                       {0, 19, 51, 0, 31},
                       {0, 42, 66, 31, 0}};
    primMST(graph);
    return 0;
}
