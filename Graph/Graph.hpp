#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include <vector>
#include <array>
/*
 * 
 * REFERENCE: two-dimensional vector creation by  ropez - http://www.cplusplus.com/forum/general/833/#msg2828
 * 
 * 
 */ 
class Graph{
	public:
	std::set<int> vertices;
	std::set<std::array<int,2>> edges;
	std::vector<std::vector<bool>>* adj_matrix;
	Graph(int);
};
#endif