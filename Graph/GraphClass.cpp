#include "GraphClass.h"
#include <sstream>

// Graph::Graph(int n):N(n),grph(n){
//     for(int i=0;i<N;i++){
//         std::cout<<"Enter vertex and adjacent vertices for
//         v="<<i+1<<std::endl; std::string input; std::getline(std::cin,input);
//         int vert;
//         std::stringstream ss(input);
//         if (input.empty()) {
//             std::cout << "No adjacent vertices entered for v=" << i + 1 <<
//             std::endl; continue;
//         }
//         while(ss>>vert){
//             if (vert != i + 1) {
//                 grph[i].push_back(vert-1);
//             } else {
//                 std::cout << "Cannot add the vertex itself as an adjacent
//                 vertex" << std::endl;
//             }
//         }
//     }
// }

Graph::Graph(int n) : N(n), grph(n) {

  std::cout << "Enter edge or \"q\" to quit:\n";
  while (true) {
    std::string input;
    std::getline(std::cin, input);

    if (input == "q")
      break;

    std::stringstream ss(input);

    if (input.empty()) {
      std::cout << "No adjacent vertices entered\n";
      continue;
    }

    int u, v, weight;

    // if(s=="NoWeight")weight=1;

    if (!(ss >> u >> v >> weight)) {
      std::cout
          << "Invalid input. Please enter three numbers or \"q\" to quit.\n";
      continue;
    }

    if (u < 1 || u > N || v < 1 || v > N || weight < 0) {
      std::cout << "Invalid vertex number. Must be between 1 and " << N
                << ".\n";
      continue;
    }

    grph[u - 1].push_back({v - 1, weight});
    grph[v - 1].push_back({u - 1, weight});
  }
}

Graph::Graph(const Graph &G) { grph = G.grph; }

int Graph::CountVertex() const { return N; }

bool Graph::AddEdge(int u, int v, int weight) {
  if (u < 1 || v < 1) {
    std::cout << "Invalid vertex number. Must be more than 1.\n";
    return false;
  }
  grph[u - 1].push_back({v - 1, weight});
  grph[v - 1].push_back({u - 1, weight});
  return true;
}

std::vector<std::pair<int, int>> &Graph::operator[](int v) {
  return grph[v - 1];
}

void Graph::ShowGraph() const {
  for (int i = 0; i < N; i++) {
    std::cout << "\nAdjacent vertex for v=" << i + 1 << std::endl;
    std::cout << "\t";
    for (auto elem : grph[i])
      std::cout << elem.first + 1 << " ";
  }
  std::cout << std::endl;
}
