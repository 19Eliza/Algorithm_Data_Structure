#include "bfs.h"
#include <queue>
#include <set>

namespace bfs {

std::vector<bool> Breadth_First_Search(Graph &graph, int s) {
  int n = graph.CountVertex();

  std::vector<bool> Discovered(n, false);
  --s;
  Discovered[s] = true;

  std::queue<int> L;
  L.push(s);

  while (!L.empty()) {
    int u = L.front();
    for (auto v : graph[u + 1]) {
      if (Discovered[v] == false) {
        Discovered[v] = true;
        L.push(v);
      }
    }
    L.pop();
  }

  return Discovered;
}

} // namespace bfs