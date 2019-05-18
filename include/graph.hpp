#ifndef _GRAPH_
#define _GRAPH_

#include "adjacency_list.hpp"
#include "graph_properties.hpp"

//
// Constants for graph properties

// type defines the edges direction
enum direction_type {directedE, bidiretionalE};


class Graph {
public:
    typedef std::vector<Vertex>::iterator vertex_iterator;
    typedef std::vector<Edge>::iterator edge_iterator;

    direction_type direction;
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

    // constructor: directed edges by default
    // gets the number of vertices and edges direction
    Graph (unsigned int __num_vertices, direction_type __dir = directedE) : direction(__dir) {
        // initialize the vector of vertices
        for (int i=0; i < __num_vertices; i++)
            vertices.push_back( Vertex(i) );
    };

    // add vertex on vertex set 
    void add_vertex (Vertex &__v) {
        vertices.push_back(__v);
    };
    // add vertex on vertex set with the int id
    void add_vertex (int __i) {
        vertices.push_back( Vertex(__i) );
    };

    // add edges on edges set
    void add_edge(Edge __e) {
        edges.push_back(__e);
        if (direction == bidiretionalE)
            edges.push_back( Edge(__e.second, __e.first) ); // reflexo
    };
    // add edge gettin tw int vertex id
    void add_edge(int _i1, int _i2) {
        add_edge( Edge(_i1, _i2) );
    };
};

#endif