#pragma once

#include<iostream>
#include<list>
#include<vector>

class Graph{
    private:
    int N;
    std::vector<std::vector<int>> grph;
    public:
    //Graph();
    Graph(int n);
    Graph(const Graph& gr);

    int CountVertex()const;
    bool AddEdge(int u, int v);

    std::vector<int>& operator[](int v);
    
    void ShowGraph()const;
};