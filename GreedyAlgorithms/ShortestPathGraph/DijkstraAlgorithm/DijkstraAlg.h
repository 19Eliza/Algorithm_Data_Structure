#pragma once

#include "GraphClass.h"
#include "PriorityQueue.h"
#include <iostream>
#include <map>

namespace DijkstraAlgorithm {
std::map<double, double> DijkstraAlgorithm(Graph G, double s);
}
