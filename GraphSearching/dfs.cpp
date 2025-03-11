#include "dfs.h"

namespace dfs {
void dfs(Graph graph, int s) {
  std::stack<int> st;
  --s;
  st.push(s);
  std::vector<bool> Explored(graph.CountVertex());
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (Explored[u] == false) {
      Explored[u] = true;
      for (auto v : graph[u])
        st.push(v);
    }
  }
}
} // namespace dfs