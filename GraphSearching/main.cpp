//#include"/root/projects/Algorithm_Data_Structure/Stack/stack_class.h"
#include "bfs.h"
#include "graph_structure.h"

int main() {
  int N;
  std::cout << "Enter count of vertex:\n";
  std::cin >> N;
  std::cin.clear();
  std::cin.ignore();
  Graph gr(N);
  gr.ShowGraph();
  for (auto elem : gr[N])
    std::cout << elem + 1 << " ";
  std::cout << std::endl;
  std::vector<bool> Discovered = bfs::Breadth_First_Search(gr, 1);
  int v = 2;
  std::cout << "Attainable:" << Discovered[v - 1];
  return 0;
}