//Depth First Search Algorithm

/*Depth first search (DFS) algorithm starts with the initial node of the graph G, and then goes to deeper and deeper until we find the goal node or the node which has no children.
The algorithm, then backtracks from the dead end towards the most recent node that is yet to be completely unexplored.
The data structure which is being used in DFS is stack.*/

/*Algorithm:
DFS(G, u)
    u.visited = true
    for each v ? G.Adj[u]
        if v.visited == false
            DFS(G,v)
     
init() {
    For each u ? G
        u.visited = false
     For each u ? G
       DFS(G, u)
}*/

#include <iostream>
#include <list>
using namespace std;

class Graph {
  int nvertices;
  list<int> *adj_lists;
  bool *vis;

   public:
  Graph(int V);
  void addEdge(int start, int dest);
  void DFS(int vertex);
};
//Graph
Graph::Graph(int vertices) {
  nvertices = vertices;
  adj_lists = new list<int>[vertices];
  vis = new bool[vertices];
}

void Graph::addEdge(int start, int end) {
  adj_lists[start].push_front(end);
}
//DFS algorithm

void Graph::DFS(int vertex) {
  vis[vertex] = true;
  list<int> adj_list = adj_lists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adj_list.begin(); i != adj_list.end(); ++i)
    if (!vis[*i])
      DFS(*i);
}

int main() {
   Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "DFS of the given graph from vertex 0 is: \n";
    g.DFS(0);
  

  return 0;
}
