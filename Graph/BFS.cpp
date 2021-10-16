/*create a queue Q 
mark v as visited and put v into Q 
while Q is non-empty 
    remove the head u of Q 
    mark and enqueue all (unvisited) neighbours of */
// BFS algorithm in C++

#include <iostream>
#include <list>

using namespace std;

class Graph {
  int num;
  list<int>* adj_list;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void BFS(int start);
};
Graph::Graph(int vertices) {
  num = vertices;
  adj_list = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest) {
  adj_list[src].push_back(dest);
  adj_list[dest].push_back(src);
}

void Graph::BFS(int start) {
  visited = new bool[num];
  for (int i = 0; i < num; i++)
    visited[i] = false;

  list<int> queue;

  visited[start] = true;
  queue.push_back(start);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "visited " << currVertex << " ";
    queue.pop_front();

    for (i = adj_list[currVertex].begin(); i != adj_list[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(3);

  return 0;
}
