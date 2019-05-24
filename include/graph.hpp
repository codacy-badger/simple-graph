#ifndef _SGRAPH_GRAPH_HPP_
#define _SGRAPH_GRAPH_HPP_

#include "adjacency.hpp"
#include "graph_properties.hpp"


/** Graph class base
 * Abstract/Virtual class, cannot be instanced
 */
class graph {
    virtual ~graph ();
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
};


/** Redefinition of adjacency types
 * 
 * Can be list or matrix, the value will define the class which
 * the graph will be represented.
 */
typedef AdjacencyList listG;
//typedef AdjacencyMatrix matrixG;


/** Graph class
 * 
 * The graph has two sets (Vertex and Edges) and a object which aims
 * represent the adjacencies of graph vertices
 */
template <class AdjType = listG>
class Graph : graph {
public:
    /** Graph constructor
     */
    explicit Graph(const unsigned int num_vertices)
};


/** DiGraph: Directed Graph class
 * 
 * The directed graph extends of graph, but yours edge methods are
 * implemented considerating an orientation on edges
 */
template <class AdjType = listG>
class Digraph : graph {

};

#endif