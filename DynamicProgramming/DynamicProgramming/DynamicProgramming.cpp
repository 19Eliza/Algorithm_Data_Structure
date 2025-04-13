#include "DynamicProgramming.h"

namespace dynamicProgramming {

int SubsetSumProblem(const std::vector<int> &w, const int &W) {

  std::size_t n = w.size();
  std::vector<std::vector<int>> M(n + 1, std::vector<int>(W + 1));

  for (auto j = 0; j <= W; ++j)
    M[0][j] = 0;

  for (auto i = 1; i <= n; ++i)
    for (auto j = 0; j <= W; ++j) {
      if (w[i - 1] > j)
        M[i][j] = M[i - 1][j];
      else
        M[i][j] = std::max(w[i - 1] + M[i - 1][j - w[i - 1]], M[i - 1][j]);
    }

  return M[n][W];
}

int KnapsackProblem(const std::vector<int> &w, const std::vector<int> &c,
                    const int &W) {

  std::size_t n = w.size();
  std::vector<std::vector<int>> M(n + 1, std::vector<int>(W + 1));

  for (auto j = 0; j <= W; ++j)
    M[0][j] = 0;

  for (auto i = 1; i <= n; ++i)
    for (auto j = 0; j <= W; ++j) {
      if (w[i - 1] > j)
        M[i][j] = M[i - 1][j];
      else
        M[i][j] = std::max(c[i - 1] + M[i - 1][j - w[i - 1]], M[i - 1][j]);
    }

  return M[n][W];
}



std::pair<int,std::set<int>> KnapsackProblemWithObjects(const std::vector<int> &w,const std::vector<int> &c, const int &W){
  
  std::size_t N = w.size();

  std::vector<std::vector<std::pair<int, int>>> M(
      N + 1, std::vector<std::pair<int, int>>(W + 1)); // пара цена-предмет

  for (int j = 0; j <= W; ++j)
    M[0][j] = std::pair<int, int>(0, -1);

  for (auto i = 1; i <= N; ++i)
    for (auto j = 0; j <= W; ++j) {
      if (w[i - 1] > j)
        M[i][j] = M[i - 1][j];
      else {
        auto max_c = std::max(c[i - 1] + M[i - 1][j - w[i - 1]].first,
                              M[i - 1][j].first);
        c[i - 1] + M[i - 1][j - w[i - 1]].first > M[i - 1][j].first
            ? M[i][j] = std::pair<int, int>(max_c, i-1)
            : M[i][j] = std::pair<int, int>(max_c, -1);
      }
    }

  std::set<int> objects;

  for (int i = N, j = W; i > 0 && j > 0; --i) {
    if (M[i][j].second == -1)
      continue;
    else {
      auto indexObject = M[i][j].second;
        if(objects.find(indexObject+1)==objects.end()){
          objects.insert(indexObject+1);
          j -= w[indexObject];
      }
    }
  }

  for_each(objects.begin(), objects.end(),
           [](int elem) { std::cout << elem << std::endl; });

  return {M[N][W].first,objects};
}


} // namespace dynamicProgramming