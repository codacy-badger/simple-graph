#ifndef _SGRAPH_ADJACENCY_HPP_
#define _SGRAPH_ADJACENCY_HPP_

#include <vector>
#include "ve_descriptors.hpp"

// adjacency class defines methods and variables witch will be
// implemented by adjacency_list and adjacency_matrix
class adjacency_base {
public:
    unsigned int num_vertices;
    unsigned int num_edges;

    virtual ~adjacency_base();

    // add edges with differents paramethers
    virtual void add_edge(Edge&);
    virtual void add_edge(Vertex&, Vertex&);
    virtual void add_edge(int, int);

    // add vertices with differents paramethers
    virtual void add_vertex(Vertex&);
    virtual void add_vertex(int);
};

//========================================================================
/**
 * Adjacency list class represents a graph through a list of lists,
 * is a specifing of adjacency
 */
class AdjacencyList : public adjacency_base, public std::vector< std::vector<Vertex> > {
public:
    // AdjacencyList gets references to vertex set and edges set
    AdjacencyList (std::vector<Vertex>& vecV, std::vector<Edge>& vecE)
     : std::vector< std::vector<Vertex> >() {

    };
};

#endif