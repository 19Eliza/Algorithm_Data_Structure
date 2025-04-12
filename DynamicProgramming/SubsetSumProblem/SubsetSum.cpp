#include "SubsetSum.h"

namespace dynamicProgramming {
int SubsetSumProblem(const std::vector<int> &w, const int &W) {

  std::size_t n = w.size();
  std::vector<std::vector<int>> M(n+1, std::vector<int>(W+1));

  for (auto j = 0; j <= W; ++j)
    M[0][j] = 0;

  for (auto i = 1; i <= n; ++i)
    for (auto j = 0; j <= W; ++j) {
      if (w[i-1] > j)
        M[i][j] = M[i - 1][j];
      else
        M[i][j] = std::max(w[i-1] + M[i - 1][j - w[i-1]], M[i - 1][j]);
    }

  return M[n][W];
}

} // namespace dynamicProgramming