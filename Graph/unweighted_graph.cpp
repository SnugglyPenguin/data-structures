#include <iostream>
#include <algorithm>
#include "Graph.hpp"

/*
 * REFERENCE: inserting an array into a set code found here: https://codeyarns.com/2010/07/16/c-stl-inserting-vector-into-set/
	 * written by: Ashwin - July 26 2010
 * 
 */ 
using namespace std;

void add_vertice(int new_vertice, Graph* graph_to_add){
	graph_to_add->vertices.insert(new_vertice);
}

void add_edge(Graph* graph_to_add, array<int,2> new_edge){
	//adds inserted edge to graph on two nodes
	copy(new_edge.begin(),new_edge.end(),inserter(graph_to_add->edges,graph_to_add->edges.end()));
	graph_to_add->edges.insert(new_edge);
	//connects the vertices to each other, instead of just directionally
	array<int,2> reverse_edge = {new_edge[1],new_edge[0]};
	copy(reverse_edge.begin(),reverse_edge.end(),inserter(graph_to_add->edges,graph_to_add->edges.end()));
}

Graph* populate_adjacency_matrix(Graph* graph_with_matrix){
	set<array<int,2>>::iterator edge_iter;
	set<int>::iterator vert_iter;
	//for use with positions in adjacency matrix vector of graph
	int x,y = 0;
	
	/* checks if a vertice is connected with another vertice
	 * increments x and y for each pass through the edges.
	 * if is connected, set position at adjacency matrix to true
	 * if not, set it to false.
	 */
	for (vert_iter = graph_with_matrix->vertices.begin(); vert_iter != graph_with_matrix->vertices.end(); vert_iter++){
		x = 0;
		y++;
		for (edge_iter = graph_with_matrix->edges.begin(); edge_iter != graph_with_matrix->edges.end(); edge_iter++){
			x++;
			array<int,2> current_edge = *edge_iter;
			if (*vert_iter == current_edge[0] || *vert_iter == current_edge[1]){
				//TODO: add to adj matrix
				graph_with_matrix->adj_matrix[x][y] = true;
			}
			else{
				graph_with_matrix->adj_matrix[x][y] = false;
			}
		}
	}
	return graph_with_matrix;
}