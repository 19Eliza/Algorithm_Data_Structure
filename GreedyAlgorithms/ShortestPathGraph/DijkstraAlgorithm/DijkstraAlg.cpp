#include "DijkstraAlg.h"
#include <limits>

namespace DijkstraAlgorithm {
std::map<double, double> DijkstraAlgorithm(Graph G, double s) {
  std::map<double, double> S; //узел-кратчайшее расстояние до узла от s
  S.insert({s, 0});

  PriorityQueue pq;
  double d = std::numeric_limits<double>::max();

  auto n = G.CountVertex();

  for (double i = 1; i <= n; i++) {
    if (i != s)
      pq.Insert({d, i});
  }

  std::vector<double> dist(n, d);
  dist[s - 1] = 0;

  while (S.size() != G.CountVertex()) {
    for (auto u : S) {
      for (auto v : G[u.first]) {
        auto d_prev = dist[v.first];
        if ((u.second + v.second) < d_prev) {
          pq.ChangeKey({d_prev, static_cast<double>(v.first)},
                       u.second + v.second);
        }
      }
    }
    auto min = pq.FindMin();
    pq.ExtractMin();
    S.insert({min.el, min.key});
  }
}
} // namespace DijkstraAlgorithm