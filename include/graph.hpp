#ifndef _SGRAPH_GRAPH_HPP_
#define _SGRAPH_GRAPH_HPP_

#include "adjacency.hpp"




/** Redefinition of adjacency types
 * 
 * Can be list or matrix, the value will define the class which
 * the graph will be represented.
 */
typedef AdjacencyList listG;
typedef AdjacencyMatrix matrixG;

/** Graph class
 * 
 * The graph has two sets (Vertex and Edges) and a object which aims
 * represent the adjacencies of graph vertices
 */
template <class AdjType = listG>
class Graph : public AdjType {
public:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    /** Graph constructor
     * @param: Number of vertices
     * 
     * Add vertices with id from 0 until @param.
     */
    explicit Graph (const unsigned int num_vertices): AdjType(num_vertices, directed) {
        static_assert(std::is_base_of<adjacency_base, AdjType>::value, "Template class is not an adjacency type");
        // create the vertices from 0 until NV
        for (int i=0; i < num_vertices; i++) {
            vertices.push_back( Vertex(i) );
        }
    };

};


/** DiGraph: Directed Graph class
 * 
 * The directed graph extends of graph, but yours edge methods are
 * implemented considerating an orientation on edges
 */
template <class AdjType = listG>
class Digraph : public graph<AdjType> {

};

#endif